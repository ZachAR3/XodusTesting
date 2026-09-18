// SPDX-License-Identifier: MIT
#include <windows.h>
#include <appmodel.h>
#include <psapi.h>
#include <tlhelp32.h>

#include "trace_config.h"

#include <algorithm>
#include <chrono>
#include <cwctype>
#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

namespace {

std::wstring lower(std::wstring value)
{
    std::transform(value.begin(), value.end(), value.begin(), [](wchar_t ch) { return static_cast<wchar_t>(towlower(ch)); });
    return value;
}

std::wstring quote_arg(const std::wstring &value)
{
    if (value.find_first_of(L" \t\"") == std::wstring::npos) return value;
    std::wstring result = L"\"";
    unsigned backslashes = 0;
    for (wchar_t ch : value) {
        if (ch == L'\\') {
            ++backslashes;
        } else if (ch == L'\"') {
            result.append(backslashes * 2 + 1, L'\\');
            result += L'\"';
            backslashes = 0;
        } else {
            result.append(backslashes, L'\\');
            backslashes = 0;
            result += ch;
        }
    }
    result.append(backslashes * 2, L'\\');
    result += L'\"';
    return result;
}

std::wstring full_path(const std::wstring &path)
{
    std::vector<wchar_t> buffer(32768);
    DWORD size = GetFullPathNameW(path.c_str(), static_cast<DWORD>(buffer.size()), buffer.data(), nullptr);
    return size && size < buffer.size() ? std::wstring(buffer.data(), size) : path;
}

std::filesystem::path launcher_directory()
{
    std::vector<wchar_t> buffer(32768);
    DWORD size = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    if (!size || size >= buffer.size()) return {};
    return std::filesystem::path(buffer.data(), buffer.data() + size).parent_path();
}

std::filesystem::path package_local_trace_root(HANDLE process)
{
    wchar_t family_name[PACKAGE_FAMILY_NAME_MAX_LENGTH]{};
    UINT32 family_name_length = ARRAYSIZE(family_name);
    if (GetPackageFamilyName(process, &family_name_length, family_name) != ERROR_SUCCESS || !family_name[0]) return {};

    wchar_t local_app_data[32768]{};
    DWORD local_app_data_length = GetEnvironmentVariableW(L"LOCALAPPDATA", local_app_data, ARRAYSIZE(local_app_data));
    if (!local_app_data_length || local_app_data_length >= ARRAYSIZE(local_app_data)) return {};
    return std::filesystem::path(local_app_data) / L"Packages" / family_name / L"LocalState" / L"XGRTRACE";
}

std::filesystem::path trace_root_for_target(HANDLE process, const std::filesystem::path &requested, bool explicit_root)
{
    if (explicit_root) return requested;
    const auto package_root = package_local_trace_root(process);
    if (package_root.empty()) return requested;
    std::wcout << L"Using package-local trace root: " << package_root.wstring() << L"\n";
    return package_root;
}

enum class ModuleCheck {
    present,
    absent,
    unknown,
};

ModuleCheck target_has_module(HANDLE process, const std::wstring &expected_path)
{
    std::vector<HMODULE> modules(256);
    DWORD bytes = 0;
    for (;;) {
        if (!EnumProcessModulesEx(process, modules.data(), static_cast<DWORD>(modules.size() * sizeof(HMODULE)),
                &bytes, LIST_MODULES_ALL)) {
            std::wcerr << L"Unable to verify the tracer module in the target: " << GetLastError() << L"\n";
            return ModuleCheck::unknown;
        }
        if (bytes <= modules.size() * sizeof(HMODULE)) break;
        const std::size_t required_count = bytes / sizeof(HMODULE) + 32;
        if (required_count > 8192) return ModuleCheck::unknown;
        modules.resize(required_count);
    }

    const std::wstring expected = lower(full_path(expected_path));
    const DWORD count = std::min<DWORD>(bytes / sizeof(HMODULE), static_cast<DWORD>(modules.size()));
    bool inspected_module = false;
    for (DWORD index = 0; index < count; ++index) {
        wchar_t path_buffer[32768]{};
        DWORD length = GetModuleFileNameExW(process, modules[index], path_buffer, ARRAYSIZE(path_buffer));
        if (!length || length >= ARRAYSIZE(path_buffer)) continue;
        inspected_module = true;
        if (lower(full_path(std::wstring(path_buffer, length))) == expected)
            return ModuleCheck::present;
    }
    return inspected_module ? ModuleCheck::absent : ModuleCheck::unknown;
}

bool target_is_x64(HANDLE process)
{
    USHORT process_machine = IMAGE_FILE_MACHINE_UNKNOWN;
    USHORT native_machine = IMAGE_FILE_MACHINE_UNKNOWN;
    if (!IsWow64Process2(process, &process_machine, &native_machine)) return true;
    if (process_machine == IMAGE_FILE_MACHINE_I386) return false;
    return native_machine == IMAGE_FILE_MACHINE_AMD64 || process_machine == IMAGE_FILE_MACHINE_AMD64;
}

class TargetMappingSecurity {
public:
    ~TargetMappingSecurity()
    {
        if (dacl_) LocalFree(dacl_);
    }

    bool Build(HANDLE process)
    {
        HANDLE token = nullptr;
        if (!OpenProcessToken(process, TOKEN_QUERY, &token)) return false;

        std::vector<BYTE> user_storage;
        std::vector<BYTE> app_container_storage;
        std::vector<BYTE> restricted_storage;
        std::vector<PSID> sids;
        PSID user_sid = nullptr;
        if (!read_sid(token, TokenUser, user_storage, &user_sid)) {
            CloseHandle(token);
            return false;
        }
        append_unique(sids, user_sid);

        PSID app_container_sid = nullptr;
        if (read_sid(token, TokenAppContainerSid, app_container_storage, &app_container_sid))
            append_unique(sids, app_container_sid);
        append_restricted_sids(token, restricted_storage, sids);
        CloseHandle(token);

        if (sids.empty()) {
            SetLastError(ERROR_INVALID_SID);
            return false;
        }
        DWORD acl_size = sizeof(ACL);
        for (PSID sid : sids) {
            if (!IsValidSid(sid)) {
                SetLastError(ERROR_INVALID_SID);
                return false;
            }
            acl_size += sizeof(ACCESS_ALLOWED_ACE) - sizeof(DWORD) + GetLengthSid(sid);
        }
        dacl_ = static_cast<PACL>(LocalAlloc(LPTR, acl_size));
        if (!dacl_) return false;
        if (!InitializeAcl(dacl_, acl_size, ACL_REVISION)) return false;
        for (PSID sid : sids) {
            // The target only needs to read the configuration mapping.  Do
            // not grant write, execute, or full access to the target token.
            if (!AddAccessAllowedAce(dacl_, ACL_REVISION, FILE_MAP_READ, sid)) return false;
        }
        if (!InitializeSecurityDescriptor(&descriptor_, SECURITY_DESCRIPTOR_REVISION)) return false;
        if (!SetSecurityDescriptorDacl(&descriptor_, TRUE, dacl_, FALSE)) return false;
        return true;
    }

    SECURITY_ATTRIBUTES Attributes()
    {
        SECURITY_ATTRIBUTES attributes{};
        attributes.nLength = sizeof(attributes);
        attributes.lpSecurityDescriptor = &descriptor_;
        return attributes;
    }

private:
    static bool read_sid(HANDLE token, TOKEN_INFORMATION_CLASS information_class,
        std::vector<BYTE> &storage, PSID *sid)
    {
        if (!sid) return false;
        *sid = nullptr;
        DWORD bytes = 0;
        GetTokenInformation(token, information_class, nullptr, 0, &bytes);
        if (!bytes) return false;
        storage.resize(bytes);
        if (!GetTokenInformation(token, information_class, storage.data(), bytes, &bytes)) return false;
        if (information_class == TokenUser) {
            auto *user = reinterpret_cast<const TOKEN_USER *>(storage.data());
            *sid = user->User.Sid;
        } else if (information_class == TokenAppContainerSid) {
            auto *app_container = reinterpret_cast<const TOKEN_APPCONTAINER_INFORMATION *>(storage.data());
            *sid = app_container->TokenAppContainer;
        }
        return *sid && IsValidSid(*sid);
    }

    static void append_unique(std::vector<PSID> &sids, PSID candidate)
    {
        if (!candidate) return;
        for (PSID existing : sids)
            if (EqualSid(existing, candidate)) return;
        sids.push_back(candidate);
    }

    static void append_restricted_sids(HANDLE token, std::vector<BYTE> &storage, std::vector<PSID> &sids)
    {
        DWORD bytes = 0;
        GetTokenInformation(token, TokenRestrictedSids, nullptr, 0, &bytes);
        if (!bytes) return;
        storage.resize(bytes);
        if (!GetTokenInformation(token, TokenRestrictedSids, storage.data(), bytes, &bytes)) return;
        const auto *groups = reinterpret_cast<const TOKEN_GROUPS *>(storage.data());
        for (DWORD index = 0; index < groups->GroupCount; ++index)
            if (IsValidSid(groups->Groups[index].Sid)) append_unique(sids, groups->Groups[index].Sid);
    }

    SECURITY_DESCRIPTOR descriptor_{};
    PACL dacl_ = nullptr;
};

HANDLE write_target_configuration(HANDLE process, DWORD pid, const std::filesystem::path &trace_root, const std::wstring &level, bool partial, bool no_wrap_async_callbacks)
{
    TargetMappingSecurity security;
    if (!security.Build(process)) {
        std::wcerr << L"Unable to build target configuration security descriptor: " << GetLastError() << L"\n";
        return nullptr;
    }
    SECURITY_ATTRIBUTES attributes = security.Attributes();
    const std::wstring name = xgrtrace::config::MappingName(pid);
    HANDLE mapping = CreateFileMappingW(INVALID_HANDLE_VALUE, &attributes, PAGE_READWRITE, 0,
        static_cast<DWORD>(sizeof(xgrtrace::config::SharedConfiguration)), name.c_str());
    if (!mapping) {
        std::wcerr << L"Unable to create target configuration mapping: " << GetLastError() << L"\n";
        return nullptr;
    }
    auto *view = static_cast<xgrtrace::config::SharedConfiguration *>(MapViewOfFile(mapping, FILE_MAP_WRITE, 0, 0, sizeof(xgrtrace::config::SharedConfiguration)));
    if (!view) {
        std::wcerr << L"Unable to map target configuration: " << GetLastError() << L"\n";
        CloseHandle(mapping);
        return nullptr;
    }
    xgrtrace::config::SharedConfiguration value{};
    value.version = xgrtrace::config::kVersion;
    value.flags = (partial ? xgrtrace::config::kPartialStart : 0u) |
        (no_wrap_async_callbacks ? xgrtrace::config::kNoWrapAsyncCallbacks : 0u);
    const std::wstring root = full_path(trace_root.wstring());
    if (root.size() >= ARRAYSIZE(value.trace_root) || level.size() >= ARRAYSIZE(value.level)) {
        std::wcerr << L"Trace root or level is too long for target configuration.\n";
        UnmapViewOfFile(view);
        CloseHandle(mapping);
        return nullptr;
    }
    wcsncpy_s(value.trace_root, root.c_str(), _TRUNCATE);
    wcsncpy_s(value.level, level.c_str(), _TRUNCATE);
    CopyMemory(view, &value, sizeof(value));
    FlushViewOfFile(view, sizeof(value));
    UnmapViewOfFile(view);
    return mapping;
}

bool inject(HANDLE process, const std::wstring &dll_path)
{
    std::wstring path = full_path(dll_path);
    SIZE_T bytes = (path.size() + 1) * sizeof(wchar_t);
    void *remote = VirtualAllocEx(process, nullptr, bytes, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!remote) {
        std::wcerr << L"Unable to allocate tracer path in target: " << GetLastError() << L"\n";
        return false;
    }
    SIZE_T written = 0;
    bool ok = WriteProcessMemory(process, remote, path.c_str(), bytes, &written) && written == bytes;
    HANDLE thread = nullptr;
    bool safe_to_free_remote = true;
    if (ok) {
        auto load_library = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "LoadLibraryW"));
        thread = CreateRemoteThread(process, nullptr, 0, load_library, remote, 0, nullptr);
        ok = thread != nullptr;
    }
    if (thread) {
        DWORD wait_result = WaitForSingleObject(thread, 10000);
        if (wait_result != WAIT_OBJECT_0) {
            ok = false;
            // Do not release the remote command-line buffer while a still-
            // running LoadLibraryW thread may be reading it. The target is
            // left untouched for attach mode; spawn mode will terminate it.
            if (wait_result == WAIT_TIMEOUT) safe_to_free_remote = false;
        } else {
            DWORD result = 0;
            GetExitCodeThread(thread, &result);
            ok = ok && result != 0;
            if (ok) {
                ModuleCheck module_check = ModuleCheck::unknown;
                for (int attempt = 0; attempt < 100; ++attempt) {
                    module_check = target_has_module(process, path);
                    if (module_check != ModuleCheck::absent) break;
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                }
                if (module_check == ModuleCheck::absent) {
                    std::wcerr << L"LoadLibraryW returned a nonzero result, but the tracer module was not present in the target.\n";
                    ok = false;
                }
            }
        }
        CloseHandle(thread);
    }
    if (safe_to_free_remote) VirtualFreeEx(process, remote, 0, MEM_RELEASE);
    if (!ok) std::wcerr << L"The tracer could not be safely loaded into the target: " << GetLastError() << L"\n";
    return ok;
}

DWORD find_process(const std::wstring &name)
{
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;
    PROCESSENTRY32W entry{sizeof(entry)};
    DWORD result = 0;
    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (lower(entry.szExeFile) == lower(name)) {
                result = entry.th32ProcessID;
                break;
            }
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return result;
}

HANDLE open_target(DWORD pid)
{
    HANDLE process = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_QUERY_LIMITED_INFORMATION |
                                     PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | SYNCHRONIZE,
                                 FALSE, pid);
    if (!process) {
        DWORD error = GetLastError();
        if (error == ERROR_ACCESS_DENIED) {
            HANDLE query_handle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
            if (query_handle) {
                std::wcerr << L"Target process " << pid
                    << L" is queryable, but Windows denied the injection access rights (error 5).\n"
                    << L"The launcher will not weaken target protections; use a target that permits supported instrumentation.\n";
                CloseHandle(query_handle);
            } else {
                std::wcerr << L"Unable to open target process " << pid << L": " << error << L"\n";
            }
        } else {
            std::wcerr << L"Unable to open target process " << pid << L": " << error << L"\n";
        }
        return nullptr;
    }
    if (!target_is_x64(process)) {
        std::wcerr << L"Target is not x86-64. This tracer intentionally supports x86-64 only.\n";
        CloseHandle(process);
        return nullptr;
    }
    return process;
}

void usage()
{
    std::wcerr << L"xgrtrace-launch --spawn <exe> [arguments...] [--dll <xgrtrace-dll.dll>] [--trace-root <dir>] [--level minimal|normal|verbose]\n"
                  L"xgrtrace-launch --attach <pid> [--dll <xgrtrace-dll.dll>] [--trace-root <dir>] [--level minimal|normal|verbose]\n"
                  L"xgrtrace-launch --watch <exe-name> [--dll <xgrtrace-dll.dll>] [--trace-root <dir>] [--level minimal|normal|verbose]\n";
}

} // namespace

int wmain(int argc, wchar_t **argv)
{
    if (argc < 3) {
        usage();
        return 2;
    }
    std::wstring mode = argv[1];
    std::wstring dll = L"xgrtrace-dll.dll";
    std::wstring level;
    bool no_wrap_async_callbacks = false;
    bool dll_explicit = false;
    bool trace_root_explicit = false;
    std::filesystem::path trace_root = std::filesystem::current_path() / L"traces";
    for (int index = 2; index < argc; ++index) {
        if (std::wstring(argv[index]) == L"--dll" && index + 1 < argc) {
            dll = argv[++index];
            dll_explicit = true;
        }
        else if (std::wstring(argv[index]) == L"--trace-root" && index + 1 < argc) {
            trace_root = argv[++index];
            trace_root_explicit = true;
        }
        else if (std::wstring(argv[index]) == L"--level" && index + 1 < argc) level = argv[++index];
        else if (std::wstring(argv[index]) == L"--no-wrap-async-callbacks") no_wrap_async_callbacks = true;
    }
    SetEnvironmentVariableW(L"XGRTRACE_ROOT", trace_root.c_str());
    if (level.empty()) {
        wchar_t existing_level[32]{};
        DWORD existing_size = GetEnvironmentVariableW(L"XGRTRACE_LEVEL", existing_level, ARRAYSIZE(existing_level));
        level = existing_size ? std::wstring(existing_level, existing_size) : L"normal";
    }
    SetEnvironmentVariableW(L"XGRTRACE_LEVEL", level.c_str());
    if (no_wrap_async_callbacks) SetEnvironmentVariableW(L"XGRTRACE_NO_WRAP_ASYNC_CALLBACKS", L"1");
    if (!dll_explicit && GetFileAttributesW(dll.c_str()) == INVALID_FILE_ATTRIBUTES) {
        const auto adjacent_dll = launcher_directory() / L"xgrtrace-dll.dll";
        if (!adjacent_dll.empty() && GetFileAttributesW(adjacent_dll.c_str()) != INVALID_FILE_ATTRIBUTES)
            dll = adjacent_dll.wstring();
    }
    dll = full_path(dll);

    if (mode == L"--spawn") {
        std::vector<std::wstring> command_parts;
        command_parts.emplace_back(argv[2]);
        for (int index = 3; index < argc; ++index) {
            if (std::wstring(argv[index]) == L"--dll" || std::wstring(argv[index]) == L"--trace-root" || std::wstring(argv[index]) == L"--level") {
                ++index;
                continue;
            }
            if (std::wstring(argv[index]) == L"--no-wrap-async-callbacks") continue;
            command_parts.emplace_back(argv[index]);
        }
        std::wstring command_line;
        for (const auto &part : command_parts) {
            if (!command_line.empty()) command_line += L' ';
            command_line += quote_arg(part);
        }
        std::vector<wchar_t> mutable_command(command_line.begin(), command_line.end());
        mutable_command.push_back(L'\0');
        STARTUPINFOW startup{sizeof(startup)};
        PROCESS_INFORMATION process_info{};
        if (!CreateProcessW(nullptr, mutable_command.data(), nullptr, nullptr, FALSE, CREATE_SUSPENDED, nullptr, nullptr, &startup, &process_info)) {
            std::wcerr << L"Unable to launch target: " << GetLastError() << L"\n";
            return 1;
        }
        HANDLE target = open_target(process_info.dwProcessId);
        if (target) {
            trace_root = trace_root_for_target(target, trace_root, trace_root_explicit);
            SetEnvironmentVariableW(L"XGRTRACE_ROOT", trace_root.c_str());
        }
        HANDLE configuration = target ? write_target_configuration(target, process_info.dwProcessId, trace_root, level, false, no_wrap_async_callbacks) : nullptr;
        bool loaded = target && configuration && inject(target, dll);
        if (configuration) CloseHandle(configuration);
        if (target) CloseHandle(target);
        if (!loaded) {
            TerminateProcess(process_info.hProcess, ERROR_DLL_INIT_FAILED);
            CloseHandle(process_info.hThread);
            CloseHandle(process_info.hProcess);
            return 1;
        }
        ResumeThread(process_info.hThread);
        WaitForSingleObject(process_info.hProcess, INFINITE);
        DWORD exit_code = 0;
        GetExitCodeProcess(process_info.hProcess, &exit_code);
        CloseHandle(process_info.hThread);
        CloseHandle(process_info.hProcess);
        return static_cast<int>(exit_code);
    }

    DWORD pid = 0;
    bool partial = false;
    if (mode == L"--attach") {
        pid = wcstoul(argv[2], nullptr, 10);
        partial = true;
    } else if (mode == L"--watch") {
        std::wcout << L"Watching for " << argv[2] << L"; launch it normally from the Xbox app.\n";
        while (!(pid = find_process(argv[2]))) std::this_thread::sleep_for(std::chrono::milliseconds(250));
        partial = true;
    } else {
        usage();
        return 2;
    }

    HANDLE target = open_target(pid);
    if (!target) return 1;
    trace_root = trace_root_for_target(target, trace_root, trace_root_explicit);
    HANDLE configuration = write_target_configuration(target, pid, trace_root, level, partial, no_wrap_async_callbacks);
    if (!configuration) {
        CloseHandle(target);
        return 1;
    }
    bool loaded = inject(target, dll);
    CloseHandle(target);
    CloseHandle(configuration);
    return loaded ? 0 : 1;
}
