// SPDX-License-Identifier: MIT
#include "runtime_hooks.h"

#include "trace_core.h"
#include "interface_metadata.h"
#include "wrappers.h"

#include <windows.h>
#include <winhttp.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <cstddef>
#include <cstring>
#include <cwchar>
#include <cstdint>
#include <filesystem>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#if XGRTRACE_HAS_DETOURS
#include <detours.h>
#endif

namespace xgrtrace::dll {
namespace {

template <typename Function>
void safe_trace(Function &&function) noexcept
{
    try {
        function();
    } catch (...) {
        // Observation failure must never cross the target ABI boundary.
    }
}

using QueryApiImplFn = HRESULT(WINAPI *)(const GUID *, const GUID *, void **);
using InitializeApiImplFn = HRESULT(WINAPI *)(ULONG, ULONG);
using InitializeApiImplExFn = HRESULT(WINAPI *)(ULONG, ULONG, char);
using InitializeApiImplEx2Fn = HRESULT(WINAPI *)(ULONG, ULONG, char, const void *);
using DllCanUnloadNowFn = HRESULT(WINAPI *)();
using UninitializeApiImplFn = HRESULT(WINAPI *)();
using XErrorReportFn = HRESULT(WINAPI *)(HRESULT, const char *);

struct LdrUnicodeString {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
};

struct LdrLoadedNotificationData {
    ULONG Flags;
    const LdrUnicodeString *FullDllName;
    const LdrUnicodeString *BaseDllName;
    PVOID DllBase;
    ULONG SizeOfImage;
};

struct LdrUnloadedNotificationData {
    ULONG Flags;
    const LdrUnicodeString *FullDllName;
    const LdrUnicodeString *BaseDllName;
    PVOID DllBase;
};

struct LdrDllNotificationData {
    ULONG NotificationReason;
    union {
        LdrLoadedNotificationData Loaded;
        LdrUnloadedNotificationData Unloaded;
    };
};

using LdrDllNotification = VOID(CALLBACK *)(ULONG, const LdrDllNotificationData *, PVOID);
using LdrRegisterDllNotificationFn = LONG(NTAPI *)(ULONG, LdrDllNotification, PVOID, PVOID *);
using LdrUnregisterDllNotificationFn = LONG(NTAPI *)(PVOID);

std::atomic<bool> stopping{false};
std::thread monitor_thread;
HMODULE runtime_module = nullptr;
std::mutex hook_mutex;
std::mutex side_effect_mutex;
HANDLE module_event = nullptr;
std::atomic<HMODULE> notified_runtime_module{nullptr};
std::atomic<bool> force_runtime_reinstall{false};
std::atomic<bool> dll_notifications_available{false};
PVOID dll_notification_cookie = nullptr;
LdrRegisterDllNotificationFn register_dll_notification = nullptr;
LdrUnregisterDllNotificationFn unregister_dll_notification = nullptr;

QueryApiImplFn real_query = nullptr;
InitializeApiImplFn real_initialize = nullptr;
InitializeApiImplExFn real_initialize_ex = nullptr;
InitializeApiImplEx2Fn real_initialize_ex2 = nullptr;
DllCanUnloadNowFn real_dll_can_unload = nullptr;
UninitializeApiImplFn real_uninitialize = nullptr;
XErrorReportFn real_error_report = nullptr;

using CreateFileWFn = HANDLE(WINAPI *)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
using DeleteFileWFn = BOOL(WINAPI *)(LPCWSTR);
using MoveFileExWFn = BOOL(WINAPI *)(LPCWSTR, LPCWSTR, DWORD);
using RegOpenKeyExWFn = LSTATUS(WINAPI *)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
using RegSetValueExWFn = LSTATUS(WINAPI *)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE *, DWORD);
using RegQueryValueExWFn = LSTATUS(WINAPI *)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
using WinHttpConnectFn = HINTERNET(WINAPI *)(HINTERNET, LPCWSTR, INTERNET_PORT, DWORD);
using WinHttpOpenRequestFn = HINTERNET(WINAPI *)(HINTERNET, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR *, DWORD);
using WinHttpSendRequestFn = BOOL(WINAPI *)(HINTERNET, LPCWSTR, DWORD, LPVOID, DWORD, DWORD, DWORD_PTR);
using WinHttpCloseHandleFn = BOOL(WINAPI *)(HINTERNET);

CreateFileWFn real_create_file = nullptr;
DeleteFileWFn real_delete_file = nullptr;
MoveFileExWFn real_move_file = nullptr;
RegOpenKeyExWFn real_reg_open_key = nullptr;
RegSetValueExWFn real_reg_set_value = nullptr;
RegQueryValueExWFn real_reg_query_value = nullptr;
WinHttpConnectFn real_winhttp_connect = nullptr;
WinHttpOpenRequestFn real_winhttp_open_request = nullptr;
WinHttpSendRequestFn real_winhttp_send_request = nullptr;
WinHttpCloseHandleFn real_winhttp_close_handle = nullptr;
bool side_effect_hooks_attempted = false;
std::unordered_map<HINTERNET, std::wstring> http_targets;

std::string quote_json(const std::string &value)
{
    std::ostringstream out;
    out << '"';
    for (unsigned char ch : value) {
        if (ch == '\\') out << "\\\\";
        else if (ch == '"') out << "\\\"";
        else if (ch == '\n') out << "\\n";
        else if (ch == '\r') out << "\\r";
        else out << static_cast<char>(ch);
    }
    out << '"';
    return out.str();
}

std::string enumerate_exports(HMODULE module)
{
    auto base = reinterpret_cast<std::uintptr_t>(module);
    auto dos = reinterpret_cast<const IMAGE_DOS_HEADER *>(base);
    if (!dos || dos->e_magic != IMAGE_DOS_SIGNATURE) return "[]";
    auto nt = reinterpret_cast<const IMAGE_NT_HEADERS *>(base + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE) return "[]";
    const auto &directory = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
    if (!directory.VirtualAddress || !directory.Size) return "[]";
    auto exports = reinterpret_cast<const IMAGE_EXPORT_DIRECTORY *>(base + directory.VirtualAddress);
    auto names = reinterpret_cast<const DWORD *>(base + exports->AddressOfNames);
    std::vector<std::string> values;
    values.reserve(exports->NumberOfNames);
    for (DWORD index = 0; index < exports->NumberOfNames; ++index)
        values.emplace_back(reinterpret_cast<const char *>(base + names[index]));
    std::sort(values.begin(), values.end());
    std::ostringstream out;
    out << '[';
    for (std::size_t index = 0; index < values.size(); ++index) {
        if (index) out << ',';
        out << quote_json(values[index]);
    }
    out << ']';
    return out.str();
}

std::string file_version(const std::wstring &path)
{
    DWORD ignored = 0;
    DWORD size = GetFileVersionInfoSizeW(path.c_str(), &ignored);
    if (!size) return {};
    std::vector<BYTE> data(size);
    if (!GetFileVersionInfoW(path.c_str(), 0, size, data.data())) return {};
    VS_FIXEDFILEINFO *info = nullptr;
    UINT info_size = 0;
    if (!VerQueryValueW(data.data(), L"\\", reinterpret_cast<void **>(&info), &info_size) || !info) return {};
    std::ostringstream out;
    out << HIWORD(info->dwFileVersionMS) << '.' << LOWORD(info->dwFileVersionMS)
        << '.' << HIWORD(info->dwFileVersionLS) << '.' << LOWORD(info->dwFileVersionLS);
    return out.str();
}

void *slot(void *self, std::uint32_t index)
{
    return trace::OriginalSlot(self, index);
}

void wrap_interface(void *interface_pointer, const GUID &iid) noexcept;

bool read_vtable(void *interface_pointer, void ***vtable)
{
    __try {
        *vtable = *reinterpret_cast<void ***>(interface_pointer);
        return *vtable != nullptr;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        *vtable = nullptr;
        return false;
    }
}

bool copy_vtable(void **destination, void **source, std::size_t bytes)
{
    __try {
        std::memcpy(destination, source, bytes);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

void CALLBACK dll_notification(ULONG reason, const LdrDllNotificationData *data, PVOID) noexcept
{
    if (!data || !module_event) return;
    const LdrUnicodeString *base_name = nullptr;
    HMODULE module = nullptr;
    if (reason == 1) {
        base_name = data->Loaded.BaseDllName;
        module = static_cast<HMODULE>(data->Loaded.DllBase);
    } else if (reason == 2) {
        base_name = data->Unloaded.BaseDllName;
        module = static_cast<HMODULE>(data->Unloaded.DllBase);
    }
    if (!base_name || !base_name->Buffer || base_name->Length == 0) return;
    constexpr wchar_t runtime_name[] = L"xgameruntime.dll";
    const auto characters = base_name->Length / sizeof(wchar_t);
    if (characters != ARRAYSIZE(runtime_name) - 1 || _wcsnicmp(base_name->Buffer, runtime_name, characters) != 0) return;
    if (reason == 1) {
        notified_runtime_module.store(module);
        force_runtime_reinstall.store(true);
    } else if (notified_runtime_module.load() == module) {
        notified_runtime_module.store(nullptr);
        // A DLL can be unloaded and later mapped at the same address.  Force
        // a fresh export lookup/hook transaction on the next load.
        force_runtime_reinstall.store(true);
    }
    SetEvent(module_event);
}

bool read_pointer_value(const void *storage, void **value) noexcept
{
    if (!storage || !value) return false;
    __try {
        *value = *reinterpret_cast<void *const *>(storage);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        *value = nullptr;
        return false;
    }
}

bool copy_wide_text_safely(LPCWSTR value, wchar_t *buffer, std::size_t maximum, std::size_t *length) noexcept
{
    if (!value || !buffer || !length || maximum == 0) return false;
    __try {
        *length = wcsnlen_s(value, maximum);
        if (*length) std::memcpy(buffer, value, *length * sizeof(wchar_t));
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        *length = 0;
        return false;
    }
}

bool read_dword_safely(const DWORD *storage, DWORD *value) noexcept
{
    if (!storage || !value) return false;
    __try {
        *value = *storage;
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        *value = 0;
        return false;
    }
}

std::wstring safe_wide_text(LPCWSTR value, std::size_t maximum = 4095) noexcept
{
    if (!value) return {};
    maximum = std::min(maximum, static_cast<std::size_t>(4095));
    std::array<wchar_t, 4096> buffer{};
    std::size_t length = 0;
    if (!copy_wide_text_safely(value, buffer.data(), maximum, &length)) return {};
    try {
        return std::wstring(buffer.data(), length);
    } catch (...) {
        return {};
    }
}

HRESULT WINAPI hook_query_interface(void *self, REFIID iid, void **out)
{
    auto original = reinterpret_cast<HRESULT(WINAPI *)(void *, REFIID, void **)>(slot(self, 0));
    if (!original) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return original(self, iid, out);
    HRESULT result = original(self, iid, out);
    void *returned = nullptr;
    const bool returned_readable = out && read_pointer_value(out, &returned);
    safe_trace([&] {
        trace::RecordQueryInterface(self, &iid, out, result, returned_readable ? returned : nullptr);
    });
    if (SUCCEEDED(result) && returned_readable && returned) wrap_interface(returned, iid);
    return result;
}

ULONG WINAPI hook_add_ref(void *self)
{
    auto original = reinterpret_cast<ULONG(WINAPI *)(void *)>(slot(self, 1));
    if (!original) return 0;
    trace::RecursionGuard guard;
    if (!guard.entered()) return original(self);
    ULONG result = original(self);
    safe_trace([&] { trace::RecordIUnknown("AddRef", self, result); });
    return result;
}

ULONG WINAPI hook_release(void *self)
{
    auto original = reinterpret_cast<ULONG(WINAPI *)(void *)>(slot(self, 2));
    if (!original) return 0;
    trace::RecursionGuard guard;
    if (!guard.entered()) return original(self);
    ULONG result = original(self);
    safe_trace([&] {
        trace::RecordIUnknown("Release", self, result);
        trace::RecordObjectReleased(self, result);
        if (!result) trace::UnregisterWrappedInterface(self);
    });
    return result;
}

HRESULT WINAPI hook_query_api(const GUID *clsid, const GUID *iid, void **out)
{
    if (!real_query) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_query(clsid, iid, out);
    HRESULT result = real_query(clsid, iid, out);
    void *returned = nullptr;
    const bool returned_readable = out && read_pointer_value(out, &returned);
    safe_trace([&] {
        trace::RecordQueryApi(clsid, iid, out, result, returned_readable ? returned : nullptr);
    });
    if (SUCCEEDED(result) && iid && returned_readable && returned) wrap_interface(returned, *iid);
    return result;
}

HRESULT WINAPI hook_initialize(ULONG gdk_version, ULONG gs_version)
{
    if (!real_initialize) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_initialize(gdk_version, gs_version);
    HRESULT result = real_initialize(gdk_version, gs_version);
    safe_trace([&] { trace::RecordInitialization("InitializeApiImpl", gdk_version, gs_version, 0, nullptr, result); });
    return result;
}

HRESULT WINAPI hook_initialize_ex(ULONG gdk_version, ULONG gs_version, char mode)
{
    if (!real_initialize_ex) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_initialize_ex(gdk_version, gs_version, mode);
    HRESULT result = real_initialize_ex(gdk_version, gs_version, mode);
    safe_trace([&] { trace::RecordInitialization("InitializeApiImplEx", gdk_version, gs_version, mode, nullptr, result); });
    return result;
}

HRESULT WINAPI hook_initialize_ex2(ULONG gdk_version, ULONG gs_version, char mode, const void *options)
{
    if (!real_initialize_ex2) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_initialize_ex2(gdk_version, gs_version, mode, options);
    HRESULT result = real_initialize_ex2(gdk_version, gs_version, mode, options);
    safe_trace([&] { trace::RecordInitialization("InitializeApiImplEx2", gdk_version, gs_version, mode, options, result); });
    return result;
}

HRESULT WINAPI hook_dll_can_unload_now()
{
    if (!real_dll_can_unload) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_dll_can_unload();
    HRESULT result = real_dll_can_unload();
    safe_trace([&] { trace::RecordRuntimeExportCall("DllCanUnloadNow", result); });
    return result;
}

HRESULT WINAPI hook_uninitialize()
{
    if (!real_uninitialize) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_uninitialize();
    HRESULT result = real_uninitialize();
    safe_trace([&] { trace::RecordRuntimeExportCall("UninitializeApiImpl", result); });
    return result;
}

HRESULT WINAPI hook_error_report(HRESULT reported_error, const char *context)
{
    if (!real_error_report) return E_FAIL;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_error_report(reported_error, context);
    HRESULT result = real_error_report(reported_error, context);
    safe_trace([&] { trace::RecordRuntimeErrorReport(reported_error, context, result); });
    return result;
}

void hook_one(const char *name, void **target, void *replacement)
{
#if XGRTRACE_HAS_DETOURS
    if (!*target) {
        trace::RecordRuntimeExportHook(name, false);
        return;
    }
    LONG result = DetourTransactionBegin();
    if (result == NO_ERROR) result = DetourUpdateThread(GetCurrentThread());
    if (result == NO_ERROR) result = DetourAttach(reinterpret_cast<PVOID *>(target), replacement);
    if (result == NO_ERROR) result = DetourTransactionCommit();
    trace::RecordRuntimeExportHook(name, result == NO_ERROR);
#else
    (void)target;
    (void)replacement;
    trace::RecordRuntimeExportHook(name, false);
#endif
}

void hook_optional(const char *name, void **target, void *replacement)
{
    if (target && *target) hook_one(name, target, replacement);
    else trace::RecordRuntimeExportHook(name, false);
}

HANDLE WINAPI hook_create_file(LPCWSTR path, DWORD desired_access, DWORD share_mode,
    LPSECURITY_ATTRIBUTES security_attributes, DWORD creation_disposition,
    DWORD flags_and_attributes, HANDLE template_file)
{
    if (!real_create_file) return INVALID_HANDLE_VALUE;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_create_file(path, desired_access, share_mode, security_attributes,
        creation_disposition, flags_and_attributes, template_file);
    HANDLE result = real_create_file(path, desired_access, share_mode, security_attributes,
        creation_disposition, flags_and_attributes, template_file);
    const DWORD error = result == INVALID_HANDLE_VALUE ? GetLastError() : ERROR_SUCCESS;
    if (!trace::IsTraceOutputPath(path))
        safe_trace([&] { trace::RecordSideEffect("file", "open", path, static_cast<std::int64_t>(error), result != INVALID_HANDLE_VALUE); });
    return result;
}

BOOL WINAPI hook_delete_file(LPCWSTR path)
{
    if (!real_delete_file) return FALSE;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_delete_file(path);
    BOOL result = real_delete_file(path);
    const DWORD error = result ? ERROR_SUCCESS : GetLastError();
    if (!trace::IsTraceOutputPath(path))
        safe_trace([&] { trace::RecordSideEffect("file", "delete", path, static_cast<std::int64_t>(error), result != FALSE); });
    return result;
}

BOOL WINAPI hook_move_file(LPCWSTR existing_path, LPCWSTR new_path, DWORD flags)
{
    if (!real_move_file) return FALSE;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_move_file(existing_path, new_path, flags);
    BOOL result = real_move_file(existing_path, new_path, flags);
    const DWORD error = result ? ERROR_SUCCESS : GetLastError();
    safe_trace([&] {
        if (!trace::IsTraceOutputPath(existing_path))
            trace::RecordSideEffect("file", "move", existing_path, static_cast<std::int64_t>(error), result != FALSE);
        if (!trace::IsTraceOutputPath(new_path))
            trace::RecordSideEffect("file", "move_to", new_path, static_cast<std::int64_t>(error), result != FALSE);
    });
    return result;
}

LSTATUS WINAPI hook_reg_open_key(HKEY root, LPCWSTR subkey, DWORD options, REGSAM desired_access, PHKEY result_key)
{
    if (!real_reg_open_key) return ERROR_PROC_NOT_FOUND;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_reg_open_key(root, subkey, options, desired_access, result_key);
    LSTATUS result = real_reg_open_key(root, subkey, options, desired_access, result_key);
    safe_trace([&] { trace::RecordSideEffect("registry", "open", subkey, result, result == ERROR_SUCCESS); });
    return result;
}

LSTATUS WINAPI hook_reg_set_value(HKEY key, LPCWSTR value_name, DWORD reserved, DWORD type, const BYTE *data, DWORD data_size)
{
    if (!real_reg_set_value) return ERROR_PROC_NOT_FOUND;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_reg_set_value(key, value_name, reserved, type, data, data_size);
    LSTATUS result = real_reg_set_value(key, value_name, reserved, type, data, data_size);
    safe_trace([&] { trace::RecordSideEffect("registry", "write", value_name, result, result == ERROR_SUCCESS, data_size); });
    return result;
}

LSTATUS WINAPI hook_reg_query_value(HKEY key, LPCWSTR value_name, LPDWORD reserved, LPDWORD type,
    LPBYTE data, LPDWORD data_size)
{
    if (!real_reg_query_value) return ERROR_PROC_NOT_FOUND;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_reg_query_value(key, value_name, reserved, type, data, data_size);
    LSTATUS result = real_reg_query_value(key, value_name, reserved, type, data, data_size);
    std::uint64_t bytes = 0;
    if (data_size) {
        DWORD value = 0;
        if (read_dword_safely(data_size, &value)) bytes = value;
    }
    safe_trace([&] { trace::RecordSideEffect("registry", "read", value_name, result, result == ERROR_SUCCESS, bytes); });
    return result;
}

HINTERNET WINAPI hook_winhttp_connect(HINTERNET session, LPCWSTR server_name, INTERNET_PORT server_port, DWORD reserved)
{
    if (!real_winhttp_connect) return nullptr;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_winhttp_connect(session, server_name, server_port, reserved);
    HINTERNET result = real_winhttp_connect(session, server_name, server_port, reserved);
    const DWORD error = result ? ERROR_SUCCESS : GetLastError();
    std::wstring target = safe_wide_text(server_name);
    if (server_port) target += L":" + std::to_wstring(server_port);
    if (result) {
        std::lock_guard lock(side_effect_mutex);
        http_targets[result] = target;
    }
    safe_trace([&] { trace::RecordSideEffect("network", "connect", target.c_str(), static_cast<std::int64_t>(error), result != nullptr); });
    return result;
}

HINTERNET WINAPI hook_winhttp_open_request(HINTERNET connection, LPCWSTR verb, LPCWSTR object_name,
    LPCWSTR version, LPCWSTR referrer, LPCWSTR *accept_types, DWORD flags)
{
    if (!real_winhttp_open_request) return nullptr;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_winhttp_open_request(connection, verb, object_name, version, referrer, accept_types, flags);
    HINTERNET result = real_winhttp_open_request(connection, verb, object_name, version, referrer, accept_types, flags);
    const DWORD error = result ? ERROR_SUCCESS : GetLastError();
    std::wstring target;
    {
        std::lock_guard lock(side_effect_mutex);
        auto found = http_targets.find(connection);
        if (found != http_targets.end()) target = found->second;
    }
    const std::wstring safe_object_name = safe_wide_text(object_name);
    if (!safe_object_name.empty()) {
        if (!target.empty() && safe_object_name[0] != L'/') target += L"/";
        target += safe_object_name;
    }
    if (result) {
        std::lock_guard lock(side_effect_mutex);
        http_targets[result] = target;
    }
    safe_trace([&] { trace::RecordSideEffect("network", "request", target.c_str(), static_cast<std::int64_t>(error), result != nullptr); });
    return result;
}

BOOL WINAPI hook_winhttp_send_request(HINTERNET request, LPCWSTR headers, DWORD headers_length,
    LPVOID optional, DWORD optional_length, DWORD total_length, DWORD_PTR context)
{
    if (!real_winhttp_send_request) return FALSE;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_winhttp_send_request(request, headers, headers_length, optional, optional_length, total_length, context);
    BOOL result = real_winhttp_send_request(request, headers, headers_length, optional, optional_length, total_length, context);
    const DWORD error = result ? ERROR_SUCCESS : GetLastError();
    std::wstring target;
    {
        std::lock_guard lock(side_effect_mutex);
        auto found = http_targets.find(request);
        if (found != http_targets.end()) target = found->second;
    }
    safe_trace([&] { trace::RecordSideEffect("network", "send", target.c_str(), static_cast<std::int64_t>(error), result != FALSE, total_length); });
    return result;
}

BOOL WINAPI hook_winhttp_close_handle(HINTERNET handle)
{
    if (!real_winhttp_close_handle) return FALSE;
    trace::RecursionGuard guard;
    if (!guard.entered()) return real_winhttp_close_handle(handle);
    BOOL result = real_winhttp_close_handle(handle);
    const DWORD error = result ? ERROR_SUCCESS : GetLastError();
    std::wstring target;
    {
        std::lock_guard lock(side_effect_mutex);
        auto found = http_targets.find(handle);
        if (found != http_targets.end()) {
            target = found->second;
            http_targets.erase(found);
        }
    }
    safe_trace([&] { trace::RecordSideEffect("network", "close", target.c_str(), static_cast<std::int64_t>(error), result != FALSE); });
    return result;
}

void install_side_effect_hooks()
{
    std::lock_guard lock(hook_mutex);
    if (side_effect_hooks_attempted) return;
    side_effect_hooks_attempted = true;

    auto kernel32 = GetModuleHandleW(L"kernel32.dll");
    real_create_file = kernel32 ? reinterpret_cast<CreateFileWFn>(GetProcAddress(kernel32, "CreateFileW")) : nullptr;
    real_delete_file = kernel32 ? reinterpret_cast<DeleteFileWFn>(GetProcAddress(kernel32, "DeleteFileW")) : nullptr;
    real_move_file = kernel32 ? reinterpret_cast<MoveFileExWFn>(GetProcAddress(kernel32, "MoveFileExW")) : nullptr;
    hook_optional("CreateFileW", reinterpret_cast<void **>(&real_create_file), reinterpret_cast<void *>(&hook_create_file));
    hook_optional("DeleteFileW", reinterpret_cast<void **>(&real_delete_file), reinterpret_cast<void *>(&hook_delete_file));
    hook_optional("MoveFileExW", reinterpret_cast<void **>(&real_move_file), reinterpret_cast<void *>(&hook_move_file));

    auto advapi32 = GetModuleHandleW(L"advapi32.dll");
    real_reg_open_key = advapi32 ? reinterpret_cast<RegOpenKeyExWFn>(GetProcAddress(advapi32, "RegOpenKeyExW")) : nullptr;
    real_reg_set_value = advapi32 ? reinterpret_cast<RegSetValueExWFn>(GetProcAddress(advapi32, "RegSetValueExW")) : nullptr;
    real_reg_query_value = advapi32 ? reinterpret_cast<RegQueryValueExWFn>(GetProcAddress(advapi32, "RegQueryValueExW")) : nullptr;
    hook_optional("RegOpenKeyExW", reinterpret_cast<void **>(&real_reg_open_key), reinterpret_cast<void *>(&hook_reg_open_key));
    hook_optional("RegSetValueExW", reinterpret_cast<void **>(&real_reg_set_value), reinterpret_cast<void *>(&hook_reg_set_value));
    hook_optional("RegQueryValueExW", reinterpret_cast<void **>(&real_reg_query_value), reinterpret_cast<void *>(&hook_reg_query_value));

    HMODULE winhttp = GetModuleHandleW(L"winhttp.dll");
    if (!winhttp) winhttp = LoadLibraryW(L"winhttp.dll");
    real_winhttp_connect = winhttp ? reinterpret_cast<WinHttpConnectFn>(GetProcAddress(winhttp, "WinHttpConnect")) : nullptr;
    real_winhttp_open_request = winhttp ? reinterpret_cast<WinHttpOpenRequestFn>(GetProcAddress(winhttp, "WinHttpOpenRequest")) : nullptr;
    real_winhttp_send_request = winhttp ? reinterpret_cast<WinHttpSendRequestFn>(GetProcAddress(winhttp, "WinHttpSendRequest")) : nullptr;
    real_winhttp_close_handle = winhttp ? reinterpret_cast<WinHttpCloseHandleFn>(GetProcAddress(winhttp, "WinHttpCloseHandle")) : nullptr;
    hook_optional("WinHttpConnect", reinterpret_cast<void **>(&real_winhttp_connect), reinterpret_cast<void *>(&hook_winhttp_connect));
    hook_optional("WinHttpOpenRequest", reinterpret_cast<void **>(&real_winhttp_open_request), reinterpret_cast<void *>(&hook_winhttp_open_request));
    hook_optional("WinHttpSendRequest", reinterpret_cast<void **>(&real_winhttp_send_request), reinterpret_cast<void *>(&hook_winhttp_send_request));
    hook_optional("WinHttpCloseHandle", reinterpret_cast<void **>(&real_winhttp_close_handle), reinterpret_cast<void *>(&hook_winhttp_close_handle));
}

void install_hooks(HMODULE module, bool force)
{
    std::lock_guard lock(hook_mutex);
    if (runtime_module == module && !force) return;
    runtime_module = module;
    real_query = reinterpret_cast<QueryApiImplFn>(GetProcAddress(module, "QueryApiImpl"));
    real_initialize = reinterpret_cast<InitializeApiImplFn>(GetProcAddress(module, "InitializeApiImpl"));
    real_initialize_ex = reinterpret_cast<InitializeApiImplExFn>(GetProcAddress(module, "InitializeApiImplEx"));
    real_initialize_ex2 = reinterpret_cast<InitializeApiImplEx2Fn>(GetProcAddress(module, "InitializeApiImplEx2"));
    real_dll_can_unload = reinterpret_cast<DllCanUnloadNowFn>(GetProcAddress(module, "DllCanUnloadNow"));
    real_uninitialize = reinterpret_cast<UninitializeApiImplFn>(GetProcAddress(module, "UninitializeApiImpl"));
    real_error_report = reinterpret_cast<XErrorReportFn>(GetProcAddress(module, "XErrorReport"));
#if XGRTRACE_HAS_DETOURS
    hook_one("QueryApiImpl", reinterpret_cast<void **>(&real_query), reinterpret_cast<void *>(&hook_query_api));
    hook_one("InitializeApiImpl", reinterpret_cast<void **>(&real_initialize), reinterpret_cast<void *>(&hook_initialize));
    hook_one("InitializeApiImplEx", reinterpret_cast<void **>(&real_initialize_ex), reinterpret_cast<void *>(&hook_initialize_ex));
    hook_one("InitializeApiImplEx2", reinterpret_cast<void **>(&real_initialize_ex2), reinterpret_cast<void *>(&hook_initialize_ex2));
    hook_optional("DllCanUnloadNow", reinterpret_cast<void **>(&real_dll_can_unload), reinterpret_cast<void *>(&hook_dll_can_unload_now));
    hook_optional("UninitializeApiImpl", reinterpret_cast<void **>(&real_uninitialize), reinterpret_cast<void *>(&hook_uninitialize));
    hook_optional("XErrorReport", reinterpret_cast<void **>(&real_error_report), reinterpret_cast<void *>(&hook_error_report));
#else
    hook_one("QueryApiImpl", nullptr, nullptr);
    hook_one("InitializeApiImpl", nullptr, nullptr);
    hook_one("InitializeApiImplEx", nullptr, nullptr);
    hook_one("InitializeApiImplEx2", nullptr, nullptr);
    hook_one("DllCanUnloadNow", nullptr, nullptr);
    hook_one("UninitializeApiImpl", nullptr, nullptr);
    hook_one("XErrorReport", nullptr, nullptr);
#endif
}

void wrap_interface_impl(void *interface_pointer, const GUID &iid)
{
    if (!interface_pointer) return;
    std::string iid_string = trace::GuidString(iid);
    const auto *metadata = generated::FindInterface(iid_string.c_str());
    if (!metadata) return;
    const auto existing_slots = trace::WrappedSlots(interface_pointer);
    if (existing_slots >= metadata->vtable_slots) {
        trace::ObserveWrappedInterface(interface_pointer, iid_string.c_str());
        return;
    }
    void **original = nullptr;
    original = trace::OriginalVtable(interface_pointer);
    if (!original && !read_vtable(interface_pointer, &original)) return;
    if (!metadata->vtable_slots) return;
    auto replacement = static_cast<void **>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, metadata->vtable_slots * sizeof(void *)));
    if (!replacement) return;
    if (!copy_vtable(replacement, original, metadata->vtable_slots * sizeof(void *))) {
        HeapFree(GetProcessHeap(), 0, replacement);
        return;
    }
    for (std::uint32_t index = 0; index < metadata->vtable_slots; ++index) {
        if (index == 0) replacement[index] = reinterpret_cast<void *>(&hook_query_interface);
        else if (index == 1) replacement[index] = reinterpret_cast<void *>(&hook_add_ref);
        else if (index == 2) replacement[index] = reinterpret_cast<void *>(&hook_release);
        else if (auto address = generated::WrapperFor(*metadata, index)) replacement[index] = reinterpret_cast<void *>(address);
    }
    const bool installed = trace::InstallWrappedInterface(interface_pointer, original, replacement, iid_string.c_str(), metadata->vtable_slots);
    if (!installed) {
        HeapFree(GetProcessHeap(), 0, replacement);
        return;
    }
    if (existing_slots) trace::RecordObjectUpgraded(interface_pointer, iid_string.c_str(), metadata->vtable_slots);
    else trace::RecordObjectCreated(interface_pointer, iid_string.c_str(), metadata->vtable_slots);
}

void wrap_interface(void *interface_pointer, const GUID &iid) noexcept
{
    try {
        wrap_interface_impl(interface_pointer, iid);
    } catch (...) {
        // A failed wrapper allocation or metadata lookup is non-fatal.
    }
}

void record_runtime_module(HMODULE module)
{
    if (!module) return;
    wchar_t path_buffer[32768]{};
    DWORD length = GetModuleFileNameW(module, path_buffer, ARRAYSIZE(path_buffer));
    std::wstring path(path_buffer, length);
    safe_trace([&] {
        trace::RecordRuntimeLoad(module, path, file_version(path), trace::Sha256File(path), enumerate_exports(module));
    });
}

void monitor()
{
    HMODULE initial = GetModuleHandleW(L"xgameruntime.dll");
    if (initial) notified_runtime_module.store(initial);
    while (!stopping.load()) {
        try {
            HMODULE module = notified_runtime_module.exchange(nullptr);
            bool force_install = false;
            if (!module) {
                if (!dll_notifications_available.load()) {
                    HMODULE observed = GetModuleHandleW(L"xgameruntime.dll");
                    const bool requested_reinstall = force_runtime_reinstall.exchange(false);
                    bool already_seen = false;
                    {
                        std::lock_guard lock(hook_mutex);
                        already_seen = runtime_module == observed;
                        if (!observed && runtime_module) {
                            runtime_module = nullptr;
                            real_query = nullptr;
                            real_initialize = nullptr;
                            real_initialize_ex = nullptr;
                            real_initialize_ex2 = nullptr;
                            real_dll_can_unload = nullptr;
                            real_uninitialize = nullptr;
                            real_error_report = nullptr;
                        }
                    }
                    if (observed && (!already_seen || requested_reinstall)) {
                        module = observed;
                        force_install = requested_reinstall;
                    }
                }
                if (module) {
                    record_runtime_module(module);
                    install_hooks(module, force_install);
                    continue;
                }
                if (!module_event) {
                    Sleep(100);
                    continue;
                }
                WaitForSingleObject(module_event, 1000);
                continue;
            }
            record_runtime_module(module);
            install_hooks(module, force_runtime_reinstall.exchange(false) || initial == module);
        } catch (...) {
            Sleep(100);
        }
    }
}

} // namespace

void StartRuntimeMonitor()
{
    stopping = false;
    module_event = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    dll_notifications_available.store(false);
    if (module_event) {
        auto ntdll = GetModuleHandleW(L"ntdll.dll");
        register_dll_notification = ntdll ? reinterpret_cast<LdrRegisterDllNotificationFn>(GetProcAddress(ntdll, "LdrRegisterDllNotification")) : nullptr;
        unregister_dll_notification = ntdll ? reinterpret_cast<LdrUnregisterDllNotificationFn>(GetProcAddress(ntdll, "LdrUnregisterDllNotification")) : nullptr;
        if (register_dll_notification) {
            const LONG status = register_dll_notification(0, dll_notification, nullptr, &dll_notification_cookie);
            dll_notifications_available.store(status == 0 && dll_notification_cookie != nullptr);
        }
    }
    install_side_effect_hooks();
    monitor_thread = std::thread(monitor);
}

void StopRuntimeMonitor()
{
    stopping = true;
    if (module_event) SetEvent(module_event);
    if (monitor_thread.joinable()) monitor_thread.join();
    if (dll_notification_cookie && unregister_dll_notification)
        unregister_dll_notification(dll_notification_cookie);
    dll_notification_cookie = nullptr;
    register_dll_notification = nullptr;
    unregister_dll_notification = nullptr;
    if (module_event) {
        CloseHandle(module_event);
        module_event = nullptr;
    }
    runtime_module = nullptr;
    notified_runtime_module.store(nullptr);
    force_runtime_reinstall.store(false);
    dll_notifications_available.store(false);
}

} // namespace xgrtrace::dll
