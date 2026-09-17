// SPDX-License-Identifier: MIT
#include <windows.h>

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

namespace {
std::string utf8(const std::wstring &value)
{
    int size = WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    std::string result(size, '\0');
    if (size) WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<int>(value.size()), result.data(), size, nullptr, nullptr);
    return result;
}

std::string escape(const std::string &value)
{
    std::string result;
    for (unsigned char ch : value) {
        if (ch == '\\') result += "\\\\";
        else if (ch == '"') result += "\\\"";
        else if (ch == '\r') result += "\\r";
        else if (ch == '\n') result += "\\n";
        else if (ch == '\t') result += "\\t";
        else if (ch < 0x20) {
            char buffer[7]{};
            sprintf_s(buffer, "\\u%04x", static_cast<unsigned>(ch));
            result += buffer;
        } else result += static_cast<char>(ch);
    }
    return result;
}

bool metadata_pid(const std::filesystem::path &path, DWORD *pid)
{
    if (!pid) return false;
    std::ifstream input(path, std::ios::binary);
    if (!input) return false;
    std::string text((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    const auto key = text.find("\"pid\"");
    if (key == std::string::npos) return false;
    const auto start = text.find_first_of("0123456789", key + 5);
    if (start == std::string::npos) return false;
    std::size_t end = start;
    while (end < text.size() && text[end] >= '0' && text[end] <= '9') ++end;
    try {
        const auto value = std::stoull(text.substr(start, end - start));
        if (value > (std::numeric_limits<DWORD>::max)()) return false;
        *pid = static_cast<DWORD>(value);
        return true;
    } catch (...) {
        return false;
    }
}

bool process_is_alive(DWORD pid)
{
    if (!pid) return false;
    HANDLE process = OpenProcess(SYNCHRONIZE | PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!process) return false;
    const DWORD result = WaitForSingleObject(process, 0);
    CloseHandle(process);
    return result == WAIT_TIMEOUT;
}

std::filesystem::file_time_type newest_write_time(const std::filesystem::path &session)
{
    std::filesystem::file_time_type newest{};
    std::error_code error;
    for (const char *name : {"metadata.json", "calls.jsonl", "callbacks.jsonl", "sideeffects.jsonl", "markers.jsonl"}) {
        const auto candidate = session / name;
        if (!std::filesystem::exists(candidate, error)) {
            error.clear();
            continue;
        }
        const auto time = std::filesystem::last_write_time(candidate, error);
        if (!error && time > newest) newest = time;
        error.clear();
    }
    return newest;
}

std::filesystem::path newest_session(const std::filesystem::path &root, DWORD requested_pid, bool *ambiguous)
{
    if (ambiguous) *ambiguous = false;
    struct Candidate {
        std::filesystem::path path;
        DWORD pid = 0;
        bool alive = false;
        std::filesystem::file_time_type modified{};
    };
    std::vector<Candidate> candidates;
    std::error_code error;
    if (!std::filesystem::exists(root, error) || error) return {};
    for (const auto &game : std::filesystem::directory_iterator(root, error)) {
        if (error) break;
        if (!game.is_directory(error) || error) {
            error.clear();
            continue;
        }
        for (const auto &session : std::filesystem::directory_iterator(game.path(), error)) {
            if (error) break;
            if (!session.is_directory(error) || error) {
                error.clear();
                continue;
            }
            DWORD pid = 0;
            if (!metadata_pid(session.path() / "metadata.json", &pid)) continue;
            if (requested_pid && pid != requested_pid) continue;
            candidates.push_back(Candidate{session.path(), pid, process_is_alive(pid), newest_write_time(session.path())});
        }
        error.clear();
    }
    if (candidates.empty()) return {};
    if (!requested_pid) {
        std::vector<const Candidate *> alive;
        for (const auto &candidate : candidates)
            if (candidate.alive) alive.push_back(&candidate);
        if (alive.size() > 1) {
            if (ambiguous) *ambiguous = true;
            return {};
        }
        if (alive.empty()) return {};
        return alive.front()->path;
    }
    std::sort(candidates.begin(), candidates.end(), [](const Candidate &left, const Candidate &right) {
        if (left.alive != right.alive) return left.alive > right.alive;
        if (left.modified != right.modified) return left.modified > right.modified;
        return left.path.generic_wstring() > right.path.generic_wstring();
    });
    return candidates.front().path;
}
}

int wmain(int argc, wchar_t **argv)
{
    if (argc < 2) {
        std::wcerr << L"Usage: xgrtrace-marker.exe [--trace-root <dir>] [--pid <pid>] <marker text>\n";
        return 2;
    }
    std::wstring marker;
    DWORD requested_pid = 0;
    std::filesystem::path requested_root;
    for (int index = 1; index < argc; ++index) {
        if (std::wstring(argv[index]) == L"--trace-root" && index + 1 < argc) {
            requested_root = argv[++index];
            continue;
        }
        if (std::wstring(argv[index]) == L"--pid" && index + 1 < argc) {
            requested_pid = wcstoul(argv[++index], nullptr, 0);
            continue;
        }
        if (std::wstring(argv[index]) == L"--help") {
            std::wcerr << L"Usage: xgrtrace-marker.exe [--trace-root <dir>] [--pid <pid>] <marker text>\n";
            return 0;
        }
        if (!marker.empty()) marker += L' ';
        marker += argv[index];
    }
    if (marker.empty()) {
        std::wcerr << L"Marker text must not be empty.\n";
        return 2;
    }
    wchar_t root_buffer[MAX_PATH * 4]{};
    DWORD root_size = GetEnvironmentVariableW(L"XGRTRACE_ROOT", root_buffer, ARRAYSIZE(root_buffer));
    std::filesystem::path root = requested_root.empty()
        ? (root_size ? std::filesystem::path(std::wstring(root_buffer, root_size)) : std::filesystem::current_path() / L"traces")
        : requested_root;
    bool ambiguous = false;
    auto session = newest_session(root, requested_pid, &ambiguous);
    if (session.empty()) {
        if (ambiguous)
            std::wcerr << L"Multiple active trace sessions were found below " << root << L"; pass --pid to select one.\n";
        else
            std::wcerr << L"No active trace session was found below " << root << L".\n";
        return 1;
    }
    auto mutex_name = std::wstring(L"Local\\XGRTRACE_MARKER");
    HANDLE mutex = CreateMutexW(nullptr, FALSE, mutex_name.c_str());
    if (!mutex || WaitForSingleObject(mutex, INFINITE) != WAIT_OBJECT_0) {
        if (mutex) CloseHandle(mutex);
        return 1;
    }
    auto path = session / "markers.jsonl";
    std::ofstream output(path, std::ios::binary | std::ios::app);
    DWORD session_pid = 0;
    metadata_pid(session / "metadata.json", &session_pid);
    const auto timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
    const auto wall_timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    output << "{\"event\":\"marker\",\"timestamp_ns\":" << timestamp
           << ",\"wall_timestamp_ns\":" << wall_timestamp
           << ",\"timestamp_clock\":\"steady_clock+system_utc\",\"pid\":" << GetCurrentProcessId()
           << ",\"session_pid\":" << session_pid
           << ",\"text\":\"" << escape(utf8(marker)) << "\",\"source\":\"xgrtrace-marker\"}\n";
    output.flush();
    ReleaseMutex(mutex);
    CloseHandle(mutex);
    std::wcout << L"Recorded marker in " << path << L"\n";
    return output ? 0 : 1;
}
