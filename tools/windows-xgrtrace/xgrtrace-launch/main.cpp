// SPDX-License-Identifier: MIT
#include <windows.h>
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

bool target_is_x64(HANDLE process)
{
    USHORT process_machine = IMAGE_FILE_MACHINE_UNKNOWN;
    USHORT native_machine = IMAGE_FILE_MACHINE_UNKNOWN;
    if (!IsWow64Process2(process, &process_machine, &native_machine)) return true;
    if (process_machine == IMAGE_FILE_MACHINE_I386) return false;
    return native_machine == IMAGE_FILE_MACHINE_AMD64 || process_machine == IMAGE_FILE_MACHINE_AMD64;
}

HANDLE write_target_configuration(DWORD pid, const std::filesystem::path &trace_root, const std::wstring &level, bool partial, bool no_wrap_async_callbacks)
{
    const std::wstring name = xgrtrace::config::MappingName(pid);
    HANDLE mapping = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0,
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
        std::wcerr << L"Unable to open target process " << pid << L": " << GetLastError() << L"\n";
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
    std::filesystem::path trace_root = std::filesystem::current_path() / L"traces";
    for (int index = 2; index < argc; ++index) {
        if (std::wstring(argv[index]) == L"--dll" && index + 1 < argc) dll = argv[++index];
        else if (std::wstring(argv[index]) == L"--trace-root" && index + 1 < argc) trace_root = argv[++index];
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
        HANDLE configuration = write_target_configuration(process_info.dwProcessId, trace_root, level, false, no_wrap_async_callbacks);
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

    HANDLE configuration = write_target_configuration(pid, trace_root, level, partial, no_wrap_async_callbacks);
    if (!configuration) return 1;
    HANDLE target = open_target(pid);
    if (!target) {
        CloseHandle(configuration);
        return 1;
    }
    bool loaded = inject(target, dll);
    CloseHandle(target);
    CloseHandle(configuration);
    return loaded ? 0 : 1;
}
