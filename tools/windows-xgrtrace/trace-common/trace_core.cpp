// Copyright (c) 2026 Xodus interoperability contributors.
// SPDX-License-Identifier: MIT
#include "trace_core.h"

#include "xgrtrace_gdk_abi.h"
#include "interface_metadata.h"
#include "trace_config.h"
#include "xgrtrace_hresult_names.h"

#include <bcrypt.h>
#include <shlwapi.h>
#include <windows.h>

#include <algorithm>
#include <array>
#include <cctype>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <cwctype>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <limits>
#include <memory>
#include <mutex>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#pragma comment(lib, "bcrypt.lib")
#pragma comment(lib, "shlwapi.lib")

namespace xgrtrace::trace {
namespace {

thread_local bool tls_in_trace = false;
std::atomic<std::uint64_t> next_call_id{1};
std::atomic<std::uint64_t> next_pointer_id{1};

struct Event {
    std::string channel;
    std::string line;
};

class TraceWriter {
public:
    explicit TraceWriter(std::filesystem::path directory) : directory_(std::move(directory)) {}

    bool Start()
    {
        std::error_code error;
        std::filesystem::create_directories(directory_, error);
        if (error) return false;
        for (const char *name : {"calls.jsonl", "callbacks.jsonl", "sideeffects.jsonl"}) {
            auto [it, inserted] = files_.emplace(name, std::ofstream(directory_ / name, std::ios::binary | std::ios::app));
            if (!inserted || !it->second.is_open()) return false;
        }
        std::ofstream notes(directory_ / "notes.md", std::ios::binary | std::ios::app);
        if (!notes) return false;
        notes << "# Session notes\n\nAdd user-visible milestone markers and observations here.\n";
        thread_ = std::thread([this] { Run(); });
        return true;
    }

    void Emit(std::string channel, std::string line)
    {
        std::lock_guard lock(mutex_);
        if (queue_.size() >= 32768) {
            ++dropped_;
            return;
        }
        queue_.push_back({std::move(channel), std::move(line)});
        condition_.notify_one();
    }

    void Stop()
    {
        {
            std::lock_guard lock(mutex_);
            stopping_ = true;
        }
        condition_.notify_one();
        if (thread_.joinable()) thread_.join();
        if (dropped_) {
            auto &file = files_["calls.jsonl"];
            file << "{\"event\":\"dropped_events\",\"count\":" << dropped_ << "}\n";
        }
        for (auto &[_, file] : files_) file.flush();
    }

private:
    void Run()
    {
        for (;;) {
            Event event;
            {
                std::unique_lock lock(mutex_);
                condition_.wait(lock, [this] { return stopping_ || !queue_.empty(); });
                if (queue_.empty() && stopping_) return;
                event = std::move(queue_.front());
                queue_.pop_front();
            }
            auto it = files_.find(event.channel);
            if (it != files_.end()) {
                it->second << event.line << '\n';
                std::streamoff position = static_cast<std::streamoff>(it->second.tellp());
                if (position >= 0 && position % (1024 * 1024) < 4096) it->second.flush();
            }
        }
    }

    std::filesystem::path directory_;
    std::unordered_map<std::string, std::ofstream> files_;
    std::deque<Event> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
    std::thread thread_;
    bool stopping_ = false;
    std::uint64_t dropped_ = 0;
};

struct CallState {
    std::uint64_t start_ns;
    std::string iid;
    std::string method;
    std::uint32_t slot;
};

struct WrappedInterface {
    void **original_vtable;
    void **wrapped_vtable;
    std::string iid;
    std::uint32_t slots;
    std::vector<std::string> observed_iids;
    // Keep superseded tables alive until the COM object is released.  An
    // in-flight call may still be executing from an older table when a
    // larger derived interface is observed.
    std::vector<void **> retired_vtables;
};

struct AsyncState {
    std::string id;
    std::uint64_t first_call_id;
    std::uint64_t start_ns;
    std::uint64_t completion_call_id = 0;
    HRESULT completion_result = E_PENDING;
    void *original_callback = nullptr;
    void *context = nullptr;
    void *queue = nullptr;
    bool started = false;
    bool completed = false;
    bool completed_by_callback = false;
    std::uint64_t completion_timestamp_ns = 0;
    bool cancelled = false;
    bool callback_wrapped = false;
    bool callback_invoked = false;
};

struct PendingHandle {
    std::string type;
    std::string key;
    std::uintptr_t value = 0;
    bool duplicate = false;
};

struct PendingHandleAction {
    std::string type;
    std::string key;
    std::uintptr_t value = 0;
    bool close = false;
};

struct HandleState {
    std::string id;
    std::string type;
    std::string key;
    std::uintptr_t value = 0;
    std::uint64_t generation = 0;
    bool active = false;
    bool announced = false;
};

struct CallbackRegistration {
    std::string kind;
    const void *original = nullptr;
    const void *context = nullptr;
    const void *queue = nullptr;
    const void *wrapper = nullptr;
    std::uint64_t registration_call_id = 0;
    std::string token_key;
    bool active = true;
};

struct AsyncPublicFields {
    void *queue = nullptr;
    void *context = nullptr;
    void *callback = nullptr;
};

std::unique_ptr<TraceWriter> writer;
std::filesystem::path session_directory;
std::filesystem::path trace_root;
std::mutex state_mutex;
std::mutex configuration_mutex;
std::unordered_map<std::uint64_t, CallState> calls;
std::unordered_map<void *, WrappedInterface> interfaces;
std::unordered_map<const void *, std::string> pointer_ids;
std::unordered_map<const void *, AsyncState> async_blocks;
std::unordered_map<std::uint64_t, std::vector<PendingHandle>> pending_handles;
std::unordered_map<std::uint64_t, std::vector<PendingHandleAction>> pending_handle_actions;
std::unordered_map<std::string, HandleState> handles;
std::unordered_map<std::string, std::uint64_t> handle_generations;
std::vector<CallbackRegistration> callback_registrations;
std::string runtime_path;
std::string runtime_version;
std::string runtime_sha256;
std::string runtime_exports = "[]";
Level level = Level::Normal;
std::atomic<bool> initialized{false};
bool metadata_partial_start = false;
std::string metadata_executable;
std::string metadata_executable_sha256;
config::SharedConfiguration process_configuration{};
std::atomic<bool> process_configuration_loaded{false};
bool no_wrap_async_callbacks = false;
std::atomic<std::uint64_t> next_async_id{1};
std::atomic<std::uint64_t> next_callback_id{1};
std::atomic<std::uint64_t> next_handle_id{1};

std::string utf8(const std::wstring &value);
std::string redact(const std::string &value, const char *type);

std::uint64_t now_ns()
{
    return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
}

std::uint64_t wall_now_ns()
{
    return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());
}

bool safe_copy_bytes(const void *source, void *destination, std::size_t size) noexcept
{
    if (!size) return true;
    if (!source || !destination) return false;
    __try {
        std::memcpy(destination, source, size);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

std::size_t safe_ansi_length(const char *value, std::size_t maximum, bool *readable) noexcept
{
    if (!value) {
        if (readable) *readable = true;
        return 0;
    }
    __try {
        if (readable) *readable = true;
        return strnlen_s(value, maximum);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (readable) *readable = false;
        return 0;
    }
}

std::size_t safe_utf16_length(const wchar_t *value, std::size_t maximum, bool *readable) noexcept
{
    if (!value) {
        if (readable) *readable = true;
        return 0;
    }
    __try {
        if (readable) *readable = true;
        return wcsnlen_s(value, maximum);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (readable) *readable = false;
        return 0;
    }
}

std::string safe_read_ansi_string(const char *value, std::size_t maximum, bool *readable, bool *truncated)
{
    if (maximum == (std::numeric_limits<std::size_t>::max)()) maximum -= 1;
    bool local_readable = true;
    const std::size_t length = safe_ansi_length(value, maximum + 1, &local_readable);
    if (readable) *readable = local_readable;
    if (truncated) *truncated = local_readable && value && length > maximum;
    if (!local_readable || !value) return {};
    const std::size_t bounded = std::min(length, maximum);
    std::vector<char> buffer(bounded);
    if (bounded && !safe_copy_bytes(value, buffer.data(), bounded)) {
        if (readable) *readable = false;
        return {};
    }
    return std::string(buffer.begin(), buffer.end());
}

std::string safe_read_utf16_string(const wchar_t *value, std::size_t maximum, bool *readable, bool *truncated)
{
    if (maximum == (std::numeric_limits<std::size_t>::max)()) maximum -= 1;
    bool local_readable = true;
    const std::size_t length = safe_utf16_length(value, maximum + 1, &local_readable);
    if (readable) *readable = local_readable;
    if (truncated) *truncated = local_readable && value && length > maximum;
    if (!local_readable || !value) return {};
    const std::size_t bounded = std::min(length, maximum);
    std::vector<wchar_t> buffer(bounded);
    if (bounded && !safe_copy_bytes(value, buffer.data(), bounded * sizeof(wchar_t))) {
        if (readable) *readable = false;
        return {};
    }
    return utf8(std::wstring(buffer.begin(), buffer.end()));
}

bool safe_async_fields(const XAsyncBlock *value, AsyncPublicFields *fields) noexcept
{
    if (!value || !fields) return false;
    __try {
        fields->queue = reinterpret_cast<void *>(value->queue);
        fields->context = value->context;
        fields->callback = reinterpret_cast<void *>(value->callback);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        *fields = {};
        return false;
    }
}

bool safe_set_async_callback(XAsyncBlock *value, void *callback) noexcept
{
    if (!value) return false;
    __try {
        value->callback = reinterpret_cast<decltype(value->callback)>(callback);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

std::string basename_utf8(const std::wstring &path)
{
    if (path.empty()) return {};
    return utf8(std::filesystem::path(path).filename().wstring());
}

bool is_identity_name(const char *name)
{
    std::string lowered(name ? name : "");
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    for (const char *needle : {"xuid", "gamertag", "localid", "local_id", "publisheruserid", "useridentifier"})
        if (lowered.find(needle) != std::string::npos) return true;
    return false;
}

std::string pseudonym(const std::string &value, const char *type);

std::string handle_key(const std::string &type, std::uintptr_t value)
{
    return type + "|" + std::to_string(value);
}

bool read_scalar_value(const void *storage, std::size_t width, std::uint64_t *value) noexcept
{
    if (!value || width == 0 || width > sizeof(*value)) return false;
    *value = 0;
    return safe_copy_bytes(storage, value, width);
}

std::string bytes_hex(const std::vector<unsigned char> &bytes)
{
    std::ostringstream out;
    for (unsigned char byte : bytes)
        out << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned>(byte);
    return out.str();
}

std::string json_array(const std::vector<std::string> &items)
{
    std::string result = "[";
    for (std::size_t index = 0; index < items.size(); ++index) {
        if (index) result += ',';
        result += items[index];
    }
    result += ']';
    return result;
}

std::wstring configured_root()
{
    if (process_configuration_loaded.load() && process_configuration.trace_root[0])
        return process_configuration.trace_root;
    wchar_t root_buffer[MAX_PATH * 4]{};
    DWORD root_size = GetEnvironmentVariableW(L"XGRTRACE_ROOT", root_buffer, ARRAYSIZE(root_buffer));
    return root_size ? std::wstring(root_buffer, root_size) : std::wstring();
}

std::wstring configured_level()
{
    if (process_configuration_loaded.load() && process_configuration.level[0])
        return process_configuration.level;
    wchar_t level_buffer[32]{};
    DWORD level_size = GetEnvironmentVariableW(L"XGRTRACE_LEVEL", level_buffer, ARRAYSIZE(level_buffer));
    return level_size ? std::wstring(level_buffer, level_size) : L"normal";
}

std::uint32_t configured_flags()
{
    return process_configuration_loaded.load() ? process_configuration.flags : 0;
}

std::string utf8(const std::wstring &value)
{
    if (value.empty()) return {};
    int size = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    if (!size) return {};
    std::string result(size, '\0');
    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(), static_cast<int>(value.size()), result.data(), size, nullptr, nullptr);
    return result;
}

std::wstring wide(const std::string &value)
{
    if (value.empty()) return {};
    int size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(), static_cast<int>(value.size()), nullptr, 0);
    if (!size) return {};
    std::wstring result(size, L'\0');
    MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(), static_cast<int>(value.size()), result.data(), size);
    return result;
}

std::string json_escape(const std::string &value)
{
    std::ostringstream out;
    for (unsigned char ch : value) {
        switch (ch) {
        case '\\': out << "\\\\"; break;
        case '"': out << "\\\""; break;
        case '\b': out << "\\b"; break;
        case '\f': out << "\\f"; break;
        case '\n': out << "\\n"; break;
        case '\r': out << "\\r"; break;
        case '\t': out << "\\t"; break;
        default:
            if (ch < 0x20) out << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<unsigned>(ch);
            else out << static_cast<char>(ch);
        }
    }
    return out.str();
}

std::string quote(const std::string &value)
{
    return "\"" + json_escape(value) + "\"";
}

void emit(const char *channel, const std::string &line)
{
    std::lock_guard lock(state_mutex);
    if (!writer || !initialized.load()) return;
    writer->Emit(channel, line);
}

class Json {
public:
    Json() { value_ = "{"; }
    void string_value(const char *name, const std::string &value)
    {
        add_name(name);
        value_ += quote(value);
    }
    void raw_value(const char *name, const std::string &value)
    {
        add_name(name);
        value_ += value;
    }
    void number(const char *name, std::uint64_t value)
    {
        add_name(name);
        value_ += std::to_string(value);
    }
    void signed_number(const char *name, std::int64_t value)
    {
        add_name(name);
        value_ += std::to_string(value);
    }
    void boolean(const char *name, bool value)
    {
        add_name(name);
        value_ += value ? "true" : "false";
    }
    std::string finish()
    {
        value_ += "}";
        return value_;
    }

private:
    void add_name(const char *name)
    {
        if (!first_) value_ += ',';
        first_ = false;
        value_ += quote(name);
        value_ += ':';
    }
    std::string value_;
    bool first_ = true;
};

std::string method_for_call(std::uint64_t call_id)
{
    std::lock_guard lock(state_mutex);
    auto it = calls.find(call_id);
    return it == calls.end() ? std::string() : it->second.method;
}

std::string handle_label(const std::string &type)
{
    std::string label;
    for (char ch : type) {
        if (std::isalnum(static_cast<unsigned char>(ch)) || ch == '_') label += ch;
    }
    return label.empty() ? "handle" : label;
}

std::string canonical_handle_type(const char *type)
{
    const std::string source = type ? type : "opaque-handle";
    std::string result;
    std::string token;
    const auto flush = [&] {
        if (!token.empty() && token != "const") result += token;
        token.clear();
    };
    for (const unsigned char ch : source) {
        if (std::isalnum(ch) || ch == '_') token += static_cast<char>(ch);
        else flush();
    }
    flush();
    return result.empty() ? "opaque-handle" : result;
}

std::uintptr_t read_handle_value(const void *storage, std::size_t width, bool *readable)
{
    std::uint64_t value = 0;
    const bool ok = width > 0 && width <= sizeof(value) && read_scalar_value(storage, width, &value);
    if (readable) *readable = ok;
    return static_cast<std::uintptr_t>(value);
}

bool method_is_close(const std::string &method)
{
    std::string lowered = method;
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return lowered.find("close") != std::string::npos || lowered.find("destroy") != std::string::npos ||
        lowered.find("release") != std::string::npos || lowered.find("unregister") != std::string::npos;
}

std::string handle_id_for(const std::string &type, const std::string &key, std::uintptr_t value, bool create_if_missing)
{
    std::lock_guard lock(state_mutex);
    auto found = handles.find(key);
    if (found != handles.end() && found->second.active) return found->second.id;
    if (!create_if_missing || !value) return {};
    const auto generation = ++handle_generations[key];
    auto &state = handles[key];
    state.id = handle_label(type) + "#" + std::to_string(next_handle_id.fetch_add(1));
    state.type = type;
    state.key = key;
    state.value = value;
    state.generation = generation;
    state.active = true;
    state.announced = false;
    return state.id;
}

std::uint64_t handle_generation_for(const std::string &key)
{
    std::lock_guard lock(state_mutex);
    auto found = handle_generations.find(key);
    return found == handle_generations.end() ? 0 : found->second;
}

void finalize_handle_state(std::uint64_t call_id, bool success)
{
    std::vector<PendingHandle> outputs;
    std::vector<PendingHandleAction> actions;
    {
        std::lock_guard lock(state_mutex);
        auto output_it = pending_handles.find(call_id);
        if (output_it != pending_handles.end()) {
            outputs = std::move(output_it->second);
            pending_handles.erase(output_it);
        }
        auto action_it = pending_handle_actions.find(call_id);
        if (action_it != pending_handle_actions.end()) {
            actions = std::move(action_it->second);
            pending_handle_actions.erase(action_it);
        }
    }
    if (success) {
        for (const auto &output : outputs) {
            if (!output.value) continue;
            const std::string id = handle_id_for(output.type, output.key, output.value, true);
            bool announce = false;
            std::uint64_t generation = 0;
            {
                std::lock_guard lock(state_mutex);
                auto found = handles.find(output.key);
                if (found != handles.end()) {
                    announce = !found->second.announced;
                    found->second.announced = true;
                    generation = found->second.generation;
                }
            }
            if (!announce) continue;
            Json event;
            event.string_value("event", "handle_create");
            event.number("call_id", call_id);
            event.string_value("type", output.type);
            event.string_value("handle_id", id);
            event.number("generation", generation);
            event.string_value("origin", output.duplicate ? "duplicate" : "output");
            event.number("timestamp_ns", now_ns());
            event.number("wall_timestamp_ns", wall_now_ns());
            emit("calls.jsonl", event.finish());
        }
        for (const auto &action : actions) {
            if (!action.close || !action.value) continue;
            std::string id;
            bool announce = false;
            std::uint64_t generation = 0;
            {
                std::lock_guard lock(state_mutex);
                auto found = handles.find(action.key);
                if (found != handles.end()) {
                    id = found->second.id;
                    announce = !found->second.announced;
                    found->second.announced = true;
                    generation = found->second.generation;
                    found->second.active = false;
                }
            }
            if (announce) {
                Json create;
                create.string_value("event", "handle_create");
                create.number("call_id", call_id);
                create.string_value("type", action.type);
                create.string_value("handle_id", id);
                create.number("generation", generation);
                create.string_value("origin", "implicit_close");
                create.number("timestamp_ns", now_ns());
                create.number("wall_timestamp_ns", wall_now_ns());
                emit("calls.jsonl", create.finish());
            }
            Json event;
            event.string_value("event", "handle_close");
            event.number("call_id", call_id);
            event.string_value("type", action.type);
            event.string_value("handle_id", id);
            event.number("value_generation", generation ? generation : handle_generation_for(action.key));
            event.number("timestamp_ns", now_ns());
            event.number("wall_timestamp_ns", wall_now_ns());
            emit("calls.jsonl", event.finish());
        }
    }
}

void finalize_callback_state(std::uint64_t call_id, bool success)
{
    if (success) return;
    std::lock_guard lock(state_mutex);
    for (auto &registration : callback_registrations)
        if (registration.registration_call_id == call_id) registration.active = false;
}

std::string sha256_text(const std::string &value)
{
    BCRYPT_ALG_HANDLE algorithm = nullptr;
    BCRYPT_HASH_HANDLE hash = nullptr;
    DWORD object_size = 0, result_size = 0;
    std::string digest_hex;
    if (BCryptOpenAlgorithmProvider(&algorithm, BCRYPT_SHA256_ALGORITHM, nullptr, 0) == 0 &&
        BCryptGetProperty(algorithm, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PUCHAR>(&object_size), sizeof(object_size), &result_size, 0) == 0) {
        std::vector<UCHAR> object(object_size);
        if (BCryptCreateHash(algorithm, &hash, object.data(), object_size, nullptr, 0, 0) == 0 &&
            BCryptHashData(hash, reinterpret_cast<PUCHAR>(const_cast<char *>(value.data())), static_cast<ULONG>(value.size()), 0) == 0) {
            std::array<UCHAR, 32> digest{};
            if (BCryptFinishHash(hash, digest.data(), static_cast<ULONG>(digest.size()), 0) == 0) {
                std::ostringstream out;
                for (UCHAR byte : digest)
                    out << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned>(byte);
                digest_hex = out.str();
            }
        }
    }
    if (hash) BCryptDestroyHash(hash);
    if (algorithm) BCryptCloseAlgorithmProvider(algorithm, 0);
    return digest_hex;
}

std::string pseudonym(const std::string &value, const char *type)
{
    Json safe;
    safe.string_value("pseudonym", "id#" + sha256_text(value).substr(0, 16));
    safe.number("length", value.size());
    safe.string_value("type", type ? type : "identity");
    return safe.finish();
}

std::string file_sha256(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input) return {};
    BCRYPT_ALG_HANDLE algorithm = nullptr;
    BCRYPT_HASH_HANDLE hash = nullptr;
    DWORD object_size = 0, result_size = 0;
    if (BCryptOpenAlgorithmProvider(&algorithm, BCRYPT_SHA256_ALGORITHM, nullptr, 0) != 0) return {};
    if (BCryptGetProperty(algorithm, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PUCHAR>(&object_size), sizeof(object_size), &result_size, 0) != 0) {
        BCryptCloseAlgorithmProvider(algorithm, 0);
        return {};
    }
    std::vector<UCHAR> object(object_size);
    if (BCryptCreateHash(algorithm, &hash, object.data(), object_size, nullptr, 0, 0) != 0) {
        BCryptCloseAlgorithmProvider(algorithm, 0);
        return {};
    }
    std::array<char, 64 * 1024> buffer{};
    while (input) {
        input.read(buffer.data(), static_cast<std::streamsize>(buffer.size()));
        auto count = input.gcount();
        if (count > 0 && BCryptHashData(hash, reinterpret_cast<PUCHAR>(buffer.data()), static_cast<ULONG>(count), 0) != 0) break;
    }
    std::array<UCHAR, 32> digest{};
    std::string result;
    if (BCryptFinishHash(hash, digest.data(), static_cast<ULONG>(digest.size()), 0) == 0) {
        std::ostringstream out;
        for (UCHAR byte : digest) out << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned>(byte);
        result = out.str();
    }
    BCryptDestroyHash(hash);
    BCryptCloseAlgorithmProvider(algorithm, 0);
    return result;
}

bool contains_secret_name(const char *name)
{
    std::string lowered(name ? name : "");
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    for (const char *needle : {"token", "ticket", "authorization", "signature", "authentication", "auth", "cookie", "credential", "secret", "password", "refresh"})
        if (lowered.find(needle) != std::string::npos) return true;
    return false;
}

bool sensitive_call(std::uint64_t call_id)
{
    const std::string method = method_for_call(call_id);
    return contains_secret_name(method.c_str());
}

bool is_location_name(const char *name)
{
    std::string lowered(name ? name : "");
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    for (const char *needle : {"path", "url", "uri", "host", "endpoint", "filename", "directory"})
        if (lowered.find(needle) != std::string::npos) return true;
    return false;
}

std::string redact(const std::string &value, const char *type)
{
    // Hashing the in-memory value uses BCrypt directly below; no token bytes
    // reach the file collector.
    BCRYPT_ALG_HANDLE algorithm = nullptr;
    BCRYPT_HASH_HANDLE hash = nullptr;
    DWORD object_size = 0, result_size = 0;
    std::string digest_hex;
    if (BCryptOpenAlgorithmProvider(&algorithm, BCRYPT_SHA256_ALGORITHM, nullptr, 0) == 0 &&
        BCryptGetProperty(algorithm, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PUCHAR>(&object_size), sizeof(object_size), &result_size, 0) == 0) {
        std::vector<UCHAR> object(object_size);
        if (BCryptCreateHash(algorithm, &hash, object.data(), object_size, nullptr, 0, 0) == 0 &&
            BCryptHashData(hash, reinterpret_cast<PUCHAR>(const_cast<char *>(value.data())), static_cast<ULONG>(value.size()), 0) == 0) {
            std::array<UCHAR, 32> digest{};
            if (BCryptFinishHash(hash, digest.data(), static_cast<ULONG>(digest.size()), 0) == 0) {
                std::ostringstream out;
                for (UCHAR byte : digest) out << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned>(byte);
                digest_hex = out.str();
            }
        }
    }
    if (hash) BCryptDestroyHash(hash);
    if (algorithm) BCryptCloseAlgorithmProvider(algorithm, 0);
    // Build a structured redaction record; raw bytes never become a trace field.
    Json safe;
    safe.boolean("redacted", true);
    safe.number("length", value.size());
    safe.string_value("sha256", digest_hex);
    safe.string_value("type", type ? type : "secret");
    return safe.finish();
}

std::string pointer_json(const void *pointer, const char *kind)
{
    Json result;
    result.boolean("null", pointer == nullptr);
    if (pointer) result.string_value("logical_id", PointerId(pointer, kind));
    return result.finish();
}

std::string windows_build();
std::string environment_string(const wchar_t *name);

void write_metadata()
{
    if (session_directory.empty()) return;
    Json metadata;
    metadata.number("schema_version", 2);
    metadata.string_value("executable_filename", metadata_executable);
    metadata.number("pid", GetCurrentProcessId());
    metadata.string_value("cpu_architecture", "x86-64");
    metadata.string_value("game_executable_sha256", metadata_executable_sha256);
    metadata.boolean("partial_start", metadata_partial_start);
    metadata.string_value("windows_build", windows_build());
    metadata.string_value("gaming_services_version", environment_string(L"XGRTRACE_GAMING_SERVICES_VERSION"));
    metadata.string_value("tracer_commit_sha", environment_string(L"XGRTRACE_COMMIT"));
    metadata.string_value("xgameruntime_source_inventory_commit", environment_string(L"XGRTRACE_SOURCE_SHA"));
    metadata.raw_value("product_store_id", "null");
    metadata.raw_value("package_family", "null");
    metadata.string_value("xgameruntime_filename", runtime_path);
    metadata.string_value("xgameruntime_file_version", runtime_version);
    metadata.string_value("xgameruntime_sha256", runtime_sha256);
    metadata.raw_value("xgameruntime_exports", runtime_exports);
    wchar_t buffer[64]{};
    SYSTEMTIME utc{};
    GetSystemTime(&utc);
    swprintf_s(buffer, L"%04u-%02u-%02uT%02u:%02u:%02uZ", utc.wYear, utc.wMonth, utc.wDay, utc.wHour, utc.wMinute, utc.wSecond);
    metadata.string_value("metadata_updated_utc", utf8(buffer));
    std::ofstream output(session_directory / "metadata.json", std::ios::binary | std::ios::trunc);
    output << metadata.finish() << '\n';
}

std::filesystem::path process_path()
{
    std::wstring buffer(32768, L'\0');
    DWORD size = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    buffer.resize(size);
    return buffer;
}

bool file_exists(const std::filesystem::path &path)
{
    return GetFileAttributesW(path.c_str()) != INVALID_FILE_ATTRIBUTES;
}

std::wstring registry_string(HKEY root, const wchar_t *subkey, const wchar_t *value_name)
{
    wchar_t buffer[256]{};
    DWORD size = sizeof(buffer);
    DWORD type = 0;
    if (RegGetValueW(root, subkey, value_name, RRF_RT_REG_SZ, &type, buffer, &size) != ERROR_SUCCESS) return {};
    return buffer;
}

std::string windows_build()
{
    auto build = registry_string(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", L"CurrentBuild");
    auto ubr = registry_string(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", L"UBR");
    return utf8(build + (ubr.empty() ? L"" : L"." + ubr));
}

std::string environment_string(const wchar_t *name)
{
    wchar_t buffer[512]{};
    DWORD size = GetEnvironmentVariableW(name, buffer, ARRAYSIZE(buffer));
    return size ? utf8(std::wstring(buffer, size)) : std::string();
}

} // namespace

RecursionGuard::RecursionGuard() noexcept : entered_(!tls_in_trace)
{
    if (entered_) tls_in_trace = true;
}

RecursionGuard::~RecursionGuard()
{
    if (entered_) tls_in_trace = false;
}

void LoadProcessConfiguration() noexcept
{
    std::lock_guard lock(configuration_mutex);
    if (process_configuration_loaded.load()) return;
    HANDLE mapping = OpenFileMappingW(FILE_MAP_READ, FALSE, config::MappingName(GetCurrentProcessId()).c_str());
    if (!mapping) return;
    auto *view = static_cast<const config::SharedConfiguration *>(MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, sizeof(config::SharedConfiguration)));
    if (view) {
        config::SharedConfiguration candidate{};
        if (safe_copy_bytes(view, &candidate, sizeof(candidate)) && candidate.version == config::kVersion) {
            candidate.trace_root[ARRAYSIZE(candidate.trace_root) - 1] = L'\0';
            candidate.level[ARRAYSIZE(candidate.level) - 1] = L'\0';
            process_configuration = candidate;
            process_configuration_loaded.store(true);
        }
        UnmapViewOfFile(view);
    }
    CloseHandle(mapping);
}

void Initialize()
{
    std::lock_guard lock(state_mutex);
    if (initialized) return;
    const auto configured_level_value = configured_level();
    if (configured_level_value == L"minimal") level = Level::Minimal;
    else if (configured_level_value == L"verbose") level = Level::Verbose;
    else level = Level::Normal;
    const auto configured_root_value = configured_root();
    trace_root = configured_root_value.empty() ? std::filesystem::current_path() / "traces" : std::filesystem::path(configured_root_value);
    no_wrap_async_callbacks = (configured_flags() & config::kNoWrapAsyncCallbacks) != 0 ||
        environment_string(L"XGRTRACE_NO_WRAP_ASYNC_CALLBACKS") == "1";
    auto executable = process_path();
    metadata_executable = utf8(executable.filename().wstring());
    metadata_executable_sha256 = file_sha256(executable);
    std::wstring partial_flag = (trace_root / (L"partial_start_" + std::to_wstring(GetCurrentProcessId()) + L".flag")).wstring();
    metadata_partial_start = (configured_flags() & config::kPartialStart) != 0 || file_exists(partial_flag);
    if (metadata_partial_start) DeleteFileW(partial_flag.c_str());
    std::wstring game_name = executable.stem().wstring();
    if (game_name.empty()) game_name = L"unknown-game";
    SYSTEMTIME utc{};
    GetSystemTime(&utc);
    wchar_t session_name[128]{};
    swprintf_s(session_name, L"%04u%02u%02uT%02u%02u%02u.%03uZ-%lu-%llu", utc.wYear, utc.wMonth, utc.wDay, utc.wHour, utc.wMinute, utc.wSecond, utc.wMilliseconds, GetCurrentProcessId(), static_cast<unsigned long long>(GetTickCount64()));
    session_directory = trace_root / game_name / session_name;
    writer = std::make_unique<TraceWriter>(session_directory);
    if (!writer->Start()) {
        writer.reset();
        return;
    }
    initialized.store(true);
    write_metadata();
}

void Shutdown()
{
    std::lock_guard lock(state_mutex);
    if (!initialized) return;
    write_metadata();
    if (writer) writer->Stop();
    writer.reset();
    initialized.store(false);
}

bool IsInitialized() noexcept { return initialized.load(); }
Level CurrentLevel() noexcept { return level; }

std::uint64_t BeginCall(const char *iid, std::uint32_t slot, const char *method, const void *self)
{
    if (!initialized) return 0;
    auto guard = RecursionGuard();
    if (!guard.entered()) return 0;
    std::uint64_t id = next_call_id.fetch_add(1);
    auto start = now_ns();
    {
        std::lock_guard lock(state_mutex);
        calls.emplace(id, CallState{start, iid ? iid : "", method ? method : "", slot});
    }
    Json event;
    event.string_value("event", "call");
    event.number("call_id", id);
    event.number("timestamp_ns", start);
    event.number("wall_timestamp_ns", wall_now_ns());
    event.number("thread_id", GetCurrentThreadId());
    event.string_value("iid", iid ? iid : "");
    event.number("slot", slot);
    event.string_value("method", method ? method : "");
    event.string_value("object", PointerId(self));
    emit("calls.jsonl", event.finish());
    return id;
}

void EndCallVoid(std::uint64_t call_id)
{
    if (!call_id || !initialized) return;
    auto guard = RecursionGuard();
    if (!guard.entered()) return;
    std::uint64_t start = now_ns();
    {
        std::lock_guard lock(state_mutex);
        auto it = calls.find(call_id);
        if (it != calls.end()) {
            start = it->second.start_ns;
            calls.erase(it);
        }
    }
    finalize_handle_state(call_id, true);
    finalize_callback_state(call_id, true);
    const auto end = now_ns();
    Json event;
    event.string_value("event", "return");
    event.number("call_id", call_id);
    event.number("timestamp_ns", end);
    event.number("wall_timestamp_ns", wall_now_ns());
    event.number("duration_us", (end - start) / 1000);
    event.string_value("return_type", "void");
    emit("calls.jsonl", event.finish());
}

void EndCallHResult(std::uint64_t call_id, HRESULT result)
{
    if (!call_id || !initialized) return;
    auto guard = RecursionGuard();
    if (!guard.entered()) return;
    std::uint64_t start = now_ns();
    {
        std::lock_guard lock(state_mutex);
        auto it = calls.find(call_id);
        if (it != calls.end()) {
            start = it->second.start_ns;
            calls.erase(it);
        }
    }
    finalize_handle_state(call_id, SUCCEEDED(result));
    finalize_callback_state(call_id, SUCCEEDED(result));
    const auto end = now_ns();
    Json event;
    event.string_value("event", "return");
    event.number("call_id", call_id);
    event.number("timestamp_ns", end);
    event.number("wall_timestamp_ns", wall_now_ns());
    event.number("duration_us", (end - start) / 1000);
    event.string_value("hresult", HResultHex(result));
    event.string_value("hresult_name", HResultName(result));
    emit("calls.jsonl", event.finish());
}

void EndCallScalar(std::uint64_t call_id, std::uint64_t result, std::size_t width, bool is_signed)
{
    if (!call_id || !initialized) return;
    auto guard = RecursionGuard();
    if (!guard.entered()) return;
    std::uint64_t start = now_ns();
    {
        std::lock_guard lock(state_mutex);
        auto it = calls.find(call_id);
        if (it != calls.end()) {
            start = it->second.start_ns;
            calls.erase(it);
        }
    }
    finalize_handle_state(call_id, result != 0);
    finalize_callback_state(call_id, result != 0);
    const auto end = now_ns();
    Json event;
    event.string_value("event", "return");
    event.number("call_id", call_id);
    event.number("timestamp_ns", end);
    event.number("wall_timestamp_ns", wall_now_ns());
    event.number("duration_us", (end - start) / 1000);
    event.string_value("result", "0x" + [&] { std::ostringstream out; out << std::hex << result; return out.str(); }());
    event.number("result_width", width);
    event.boolean("result_signed", is_signed);
    emit("calls.jsonl", event.finish());
}

void RecordScalarNumber(std::uint64_t call_id, const char *name, std::uint64_t value, std::size_t width, bool is_signed)
{
    if (!call_id || level == Level::Minimal) return;
    if (contains_secret_name(name)) {
        Json event;
        event.string_value("event", "argument");
        event.number("call_id", call_id);
        event.string_value("name", name);
        event.raw_value("value", redact(std::to_string(value), "sensitive-scalar"));
        emit("calls.jsonl", event.finish());
        return;
    }
    if (is_identity_name(name)) {
        Json event;
        event.string_value("event", "argument");
        event.number("call_id", call_id);
        event.string_value("name", name);
        event.raw_value("value", pseudonym(std::to_string(value), "identity-scalar"));
        emit("calls.jsonl", event.finish());
        return;
    }
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.string_value("value", "0x" + [&] { std::ostringstream out; out << std::hex << value; return out.str(); }());
    event.number("width", width);
    event.boolean("signed", is_signed);
    emit("calls.jsonl", event.finish());
}

void RecordScalarText(std::uint64_t call_id, const char *name, const char *value)
{
    if (!call_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    bool readable = true;
    bool truncated = false;
    std::string text = safe_read_ansi_string(value, 16 * 1024, &readable, &truncated);
    if (contains_secret_name(name)) event.raw_value("value", redact(text, "secret-scalar"));
    else if (is_identity_name(name)) event.raw_value("value", pseudonym(text, "identity"));
    else if (is_location_name(name)) event.raw_value("value", redact(text, "location-scalar"));
    else event.string_value("value", text);
    event.boolean("readable", readable);
    event.boolean("truncated", truncated);
    emit("calls.jsonl", event.finish());
}

void RecordScalarFloat(std::uint64_t call_id, const char *name, double value)
{
    if (!call_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", std::to_string(value));
    emit("calls.jsonl", event.finish());
}

void RecordInputString(std::uint64_t call_id, const char *name, const char *value, ArgumentKind kind)
{
    if (!call_id || level == Level::Minimal) return;
    constexpr std::size_t maximum = 16 * 1024;
    bool readable = true;
    bool truncated = false;
    std::string text = safe_read_ansi_string(value, maximum, &readable, &truncated);
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    if (kind == ArgumentKind::StringSensitive || contains_secret_name(name)) event.raw_value("value", redact(text, "secret-string"));
    else if (is_identity_name(name)) event.raw_value("value", pseudonym(text, "identity-string"));
    else if (is_location_name(name)) event.raw_value("value", redact(text, "location-string"));
    else {
        event.string_value("value", text);
        event.boolean("truncated", truncated);
    }
    event.boolean("readable", readable);
    emit("calls.jsonl", event.finish());
}

void RecordInputString(std::uint64_t call_id, const char *name, const wchar_t *value, ArgumentKind kind)
{
    constexpr std::size_t maximum = 16 * 1024;
    bool readable = true;
    bool truncated = false;
    std::string text = safe_read_utf16_string(value, maximum, &readable, &truncated);
    if (!call_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    if (kind == ArgumentKind::StringSensitive || contains_secret_name(name)) event.raw_value("value", redact(text, "secret-wstring"));
    else if (is_identity_name(name)) event.raw_value("value", pseudonym(text, "identity-wstring"));
    else if (is_location_name(name)) event.raw_value("value", redact(text, "location-wstring"));
    else event.string_value("value", text);
    event.boolean("readable", readable);
    event.boolean("truncated", truncated);
    emit("calls.jsonl", event.finish());
}

void RecordInputStringArray(std::uint64_t call_id, const char *name, const void *values, std::size_t count, std::size_t maximum_length, bool utf16_value, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    constexpr std::size_t maximum_items = 4096;
    maximum_length = maximum_length ? std::min(maximum_length, static_cast<std::size_t>(16 * 1024)) : 16 * 1024;
    const std::size_t bounded_count = std::min(count, maximum_items);
    const std::size_t readable_count = values ? bounded_count : 0;
    std::vector<std::string> items;
    items.reserve(readable_count);
    bool readable = values != nullptr || bounded_count == 0;
    for (std::size_t index = 0; index < readable_count; ++index) {
        const void *item = nullptr;
        if (!safe_copy_bytes(static_cast<const unsigned char *>(values) + index * sizeof(void *), &item, sizeof(item))) {
            readable = false;
            break;
        }
        bool item_readable = true;
        bool item_truncated = false;
        std::string value = utf16_value
            ? safe_read_utf16_string(static_cast<const wchar_t *>(item), maximum_length, &item_readable, &item_truncated)
            : safe_read_ansi_string(static_cast<const char *>(item), maximum_length, &item_readable, &item_truncated);
        readable = readable && item_readable;
        items.push_back((sensitive || contains_secret_name(name)) ? redact(value, "secret-string-array") :
            (is_identity_name(name) ? pseudonym(value, "identity-string-array") :
                (is_location_name(name) ? redact(value, "location-string-array") : quote(value))));
    }
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", json_array(items));
    event.number("count", count);
    event.boolean("truncated", count > readable_count);
    event.boolean("readable", readable);
    emit("calls.jsonl", event.finish());
}

void RecordInputStringArrayFromCountPointer(std::uint64_t call_id, const char *name, const void *values,
    const void *count_storage, std::size_t count_width, std::size_t maximum_length, bool utf16_value, bool sensitive)
{
    std::uint64_t count = 0;
    if (!read_scalar_value(count_storage, count_width, &count)) count = 0;
    const auto bounded_count = std::min<std::uint64_t>(count, (std::numeric_limits<std::size_t>::max)());
    RecordInputStringArray(call_id, name, values, static_cast<std::size_t>(bounded_count), maximum_length, utf16_value, sensitive);
}

void RecordInputBuffer(std::uint64_t call_id, const char *name, const void *value, std::size_t size, const char *type, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    constexpr std::size_t maximum = 64 * 1024;
    const std::size_t bounded = std::min(size, maximum);
    std::vector<unsigned char> bytes(bounded);
    const bool readable = !bounded || safe_copy_bytes(value, bytes.data(), bounded);
    Json data;
    data.string_value("type", type ? type : "buffer");
    data.number("size", size);
    data.boolean("readable", readable);
    data.boolean("truncated", size > bounded);
    if (sensitive) data.raw_value("data", redact(bytes_hex(bytes), "sensitive-buffer"));
    else data.string_value("bytes_hex", readable ? bytes_hex(bytes) : std::string());
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", data.finish());
    emit("calls.jsonl", event.finish());
}

void RecordOutputBuffer(std::uint64_t call_id, const char *name, const void *value, std::size_t capacity, const void *used, std::size_t used_width, std::size_t unit_size, const char *type, OutputEncoding encoding, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    sensitive = sensitive || sensitive_call(call_id);
    constexpr std::size_t maximum = 64 * 1024;
    if (!unit_size) unit_size = 1;
    std::uint64_t used_units = capacity;
    bool used_readable = true;
    if (used && used_width) {
        used_readable = read_scalar_value(used, used_width, &used_units);
        if (!used_readable) used_units = 0;
    }
    const std::uint64_t reported_bytes = used && unit_size > 0 && used_units <= (std::numeric_limits<std::uint64_t>::max)() / unit_size
        ? used_units * unit_size : static_cast<std::uint64_t>(capacity);
    const std::uint64_t requested_bytes = std::min<std::uint64_t>(reported_bytes, capacity);
    const std::size_t bounded = static_cast<std::size_t>(std::min<std::uint64_t>(requested_bytes, maximum));
    std::vector<unsigned char> bytes(bounded);
    const bool readable = !bounded || safe_copy_bytes(value, bytes.data(), bounded);
    Json data;
    data.string_value("type", type ? type : "buffer");
    data.number("capacity", capacity);
    data.number("used", used_units);
    data.number("captured_bytes", bounded);
    data.boolean("used_readable", used_readable);
    data.boolean("readable", readable);
    data.boolean("truncated", reported_bytes > bounded || reported_bytes > capacity);
    if (sensitive) {
        data.raw_value("value", redact(bytes_hex(bytes), "sensitive-output"));
    } else if (encoding == OutputEncoding::Ansi) {
        bool string_readable = readable;
        bool string_truncated = false;
        const std::size_t string_limit = std::min<std::size_t>(bounded, maximum);
        std::string text = safe_read_ansi_string(static_cast<const char *>(value), string_limit, &string_readable, &string_truncated);
        if (is_location_name(name)) data.raw_value("value", redact(text, "location-output"));
        else data.string_value("value", text);
        data.boolean("string_readable", string_readable);
        data.boolean("string_truncated", string_truncated || requested_bytes > bounded);
    } else if (encoding == OutputEncoding::Utf16) {
        const std::size_t character_count = bounded / sizeof(wchar_t);
        std::vector<wchar_t> wide_value(character_count);
        const bool wide_readable = !character_count || safe_copy_bytes(value, wide_value.data(), character_count * sizeof(wchar_t));
        const std::string text = wide_readable ? utf8(std::wstring(wide_value.begin(), wide_value.end())) : std::string();
        if (is_location_name(name)) data.raw_value("value", redact(text, "location-output"));
        else data.string_value("value", text);
        data.boolean("string_readable", wide_readable);
    } else {
        data.string_value("bytes_hex", readable ? bytes_hex(bytes) : std::string());
    }
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", data.finish());
    emit("calls.jsonl", event.finish());
}

void RecordOutputStringArray(std::uint64_t call_id, const char *name, const void *values, std::size_t count, std::size_t maximum_length, bool utf16_value, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    sensitive = sensitive || sensitive_call(call_id);
    constexpr std::size_t maximum_items = 4096;
    maximum_length = maximum_length ? std::min(maximum_length, static_cast<std::size_t>(16 * 1024)) : 16 * 1024;
    const std::size_t bounded_count = std::min(count, maximum_items);
    const std::size_t readable_count = values ? bounded_count : 0;
    std::vector<std::string> items;
    items.reserve(readable_count);
    bool readable = values != nullptr || bounded_count == 0;
    for (std::size_t index = 0; index < readable_count; ++index) {
        void *item = nullptr;
        if (!safe_copy_bytes(static_cast<const unsigned char *>(values) + index * sizeof(void *), &item, sizeof(item))) {
            readable = false;
            break;
        }
        bool item_readable = true;
        bool item_truncated = false;
        std::string text = utf16_value
            ? safe_read_utf16_string(static_cast<const wchar_t *>(item), maximum_length, &item_readable, &item_truncated)
            : safe_read_ansi_string(static_cast<const char *>(item), maximum_length, &item_readable, &item_truncated);
        readable = readable && item_readable;
        items.push_back((sensitive || contains_secret_name(name)) ? redact(text, "secret-output-string-array") :
            (is_location_name(name) ? redact(text, "location-output-string-array") : quote(text)));
    }
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", json_array(items));
    event.number("count", count);
    event.boolean("truncated", count > readable_count);
    event.boolean("readable", readable);
    emit("calls.jsonl", event.finish());
}

void RecordOutputScalarValue(std::uint64_t call_id, const char *name, const void *value, std::size_t width, bool is_signed, const char *type, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    sensitive = sensitive || sensitive_call(call_id);
    std::uint64_t raw = 0;
    const bool readable = read_scalar_value(value, std::min(width, sizeof(raw)), &raw);
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.string_value("type", type ? type : "scalar");
    event.number("width", width);
    event.boolean("readable", readable);
    if (sensitive) {
        event.raw_value("value", redact(std::to_string(raw), "sensitive-output-scalar"));
    } else if (is_signed && width < sizeof(raw)) {
        const unsigned shift = static_cast<unsigned>((sizeof(raw) - width) * 8);
        event.signed_number("value", static_cast<std::int64_t>(raw << shift) >> shift);
    } else if (is_signed) {
        event.signed_number("value", static_cast<std::int64_t>(raw));
    } else {
        event.number("value", raw);
    }
    emit("calls.jsonl", event.finish());
}

void RecordOutputValue(std::uint64_t call_id, const char *name, const void *value, std::size_t size, const char *type, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    sensitive = sensitive || sensitive_call(call_id);
    constexpr std::size_t maximum = 64 * 1024;
    const std::size_t bounded = std::min(size, maximum);
    std::vector<unsigned char> bytes(bounded);
    const bool readable = !bounded || safe_copy_bytes(value, bytes.data(), bounded);
    Json data;
    data.string_value("type", type ? type : "object");
    data.number("size", size);
    data.boolean("readable", readable);
    data.boolean("truncated", size > bounded);
    if (sensitive) data.raw_value("value", redact(bytes_hex(bytes), "sensitive-output-object"));
    else data.string_value("bytes_hex", readable ? bytes_hex(bytes) : std::string());
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", data.finish());
    emit("calls.jsonl", event.finish());
}

void RecordOutputPointeeValue(std::uint64_t call_id, const char *name, const void *storage,
    std::size_t pointer_width, std::size_t pointee_size, const char *type, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    sensitive = sensitive || sensitive_call(call_id);
    std::uint64_t raw = 0;
    const bool pointer_readable = read_scalar_value(storage, std::min(pointer_width, sizeof(raw)), &raw);
    constexpr std::size_t maximum = 64 * 1024;
    const std::size_t bounded = std::min(pointee_size, maximum);
    std::vector<unsigned char> bytes(bounded);
    const bool pointee_readable = !raw || !bounded || safe_copy_bytes(
        reinterpret_cast<const void *>(static_cast<std::uintptr_t>(raw)), bytes.data(), bounded);
    Json value;
    value.string_value("type", type ? type : "pointer");
    value.boolean("pointer_readable", pointer_readable);
    value.boolean("null", raw == 0);
    if (pointer_readable && raw)
        value.string_value("logical_id", PointerId(reinterpret_cast<const void *>(static_cast<std::uintptr_t>(raw)), "output-pointee"));
    value.number("pointee_size", pointee_size);
    value.boolean("pointee_readable", pointer_readable && pointee_readable);
    value.boolean("truncated", pointee_size > bounded);
    if (sensitive) value.raw_value("bytes", redact(bytes_hex(bytes), "sensitive-output-pointee"));
    else value.string_value("bytes_hex", pointer_readable && pointee_readable ? bytes_hex(bytes) : std::string());
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", value.finish());
    emit("calls.jsonl", event.finish());
}

void RecordOutputPointerValue(std::uint64_t call_id, const char *name, const void *storage, std::size_t width, const char *type, bool sensitive)
{
    if (!call_id || level == Level::Minimal) return;
    sensitive = sensitive || sensitive_call(call_id);
    std::uint64_t raw = 0;
    const bool readable = read_scalar_value(storage, std::min(width, sizeof(raw)), &raw);
    Json value;
    value.string_value("type", type ? type : "pointer");
    value.boolean("readable", readable);
    value.boolean("null", !raw);
    if (readable && raw) value.string_value("logical_id", PointerId(reinterpret_cast<const void *>(static_cast<std::uintptr_t>(raw)), "output-pointer"));
    if (sensitive) value.boolean("redacted", true);
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", value.finish());
    emit("calls.jsonl", event.finish());
}

void RecordOutputString(std::uint64_t call_id, const char *name, const void *value, ArgumentKind kind)
{
    if (!call_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", pointer_json(value, "output"));
    event.boolean("redacted", kind == ArgumentKind::OutputString);
    emit("calls.jsonl", event.finish());
}

void RecordPointer(std::uint64_t call_id, const char *name, const void *value, ArgumentKind kind)
{
    if (!call_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "argument");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", pointer_json(value, kind == ArgumentKind::Handle ? "handle" : "pointer"));
    emit("calls.jsonl", event.finish());
}

void RecordOutputPointer(std::uint64_t call_id, const char *name, const void *value)
{
    if (!call_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", pointer_json(value, "output"));
    emit("calls.jsonl", event.finish());
}

void RecordOpaqueHandle(std::uint64_t call_id, const char *name, const void *value)
{
    RecordHandleArgument(call_id, name, &value, sizeof(value), "opaque-handle");
}

void RecordHandleArgument(std::uint64_t call_id, const char *name, const void *value, std::size_t width, const char *type)
{
    if (!call_id || level == Level::Minimal) return;
    bool readable = true;
    const auto raw = read_handle_value(value, width, &readable);
    const std::string declared_type = canonical_handle_type(type);
    const std::string key = handle_key(declared_type, raw);
    std::string id = handle_id_for(declared_type, key, raw, true);
    bool announce_preexisting = false;
    std::uint64_t generation = 0;
    const std::string method = method_for_call(call_id);
    const bool close = method_is_close(method);
    {
        std::lock_guard lock(state_mutex);
        auto found = handles.find(key);
        if (found != handles.end() && found->second.active && raw && !found->second.announced) {
            found->second.announced = true;
            generation = found->second.generation;
            announce_preexisting = true;
        }
        if (close && raw)
            pending_handle_actions[call_id].push_back(PendingHandleAction{declared_type, key, raw, true});
    }
    if (announce_preexisting) {
        Json create;
        create.string_value("event", "handle_create");
        create.number("call_id", call_id);
        create.string_value("type", declared_type);
        create.string_value("handle_id", id);
        create.number("generation", generation);
        create.string_value("origin", "preexisting");
        create.number("timestamp_ns", now_ns());
        create.number("wall_timestamp_ns", wall_now_ns());
        emit("calls.jsonl", create.finish());
    }
    Json value_json;
    value_json.string_value("type", declared_type);
    value_json.boolean("null", raw == 0);
    value_json.boolean("readable", readable);
    if (raw && !id.empty()) value_json.string_value("logical_id", id);
    Json event;
    event.string_value("event", "handle");
    event.number("call_id", call_id);
    event.string_value("name", name);
    std::string lowered_method = method;
    std::transform(lowered_method.begin(), lowered_method.end(), lowered_method.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    event.string_value("operation", close ? "close" : (lowered_method.find("duplicate") != std::string::npos ? "duplicate" : "use"));
    event.raw_value("value", value_json.finish());
    emit("calls.jsonl", event.finish());
}

void RecordOutputHandleValue(std::uint64_t call_id, const char *name, const void *storage, std::size_t width, const char *type)
{
    if (!call_id || level == Level::Minimal) return;
    bool readable = true;
    const auto raw = read_handle_value(storage, width, &readable);
    const std::string declared_type = canonical_handle_type(type);
    const std::string key = handle_key(declared_type, raw);
    const std::string method = method_for_call(call_id);
    std::string lowered_method = method;
    std::transform(lowered_method.begin(), lowered_method.end(), lowered_method.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    {
        std::lock_guard lock(state_mutex);
        pending_handles[call_id].push_back(PendingHandle{declared_type, key, raw, lowered_method.find("duplicate") != std::string::npos});
    }
    Json value;
    value.string_value("type", declared_type);
    value.boolean("null", raw == 0);
    value.boolean("readable", readable);
    value.boolean("pending", true);
    Json event;
    event.string_value("event", "output");
    event.number("call_id", call_id);
    event.string_value("name", name);
    event.raw_value("value", value.finish());
    emit("calls.jsonl", event.finish());
}

void RecordAsyncArgument(std::uint64_t call_id, const char *name, const void *value)
{
    RecordPointer(call_id, name, value, ArgumentKind::Pointer);
}

void __stdcall async_completion_thunk(XAsyncBlock *value) noexcept;

bool async_start_method(const std::string &method)
{
    std::string lowered = method;
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    const bool ends_with_async = lowered.size() >= 5 && lowered.compare(lowered.size() - 5, 5, "async") == 0;
    return lowered == "xasyncbegin" || lowered == "xasyncrun" || lowered == "xasyncschedule" || ends_with_async;
}

void RecordAsyncBlock(std::uint64_t call_id, const char *name, const XAsyncBlock *value)
{
    if (!call_id || level == Level::Minimal) return;
    RecordPointer(call_id, name, value, ArgumentKind::Pointer);
    if (!value) return;
    const std::string method = method_for_call(call_id);
    const bool is_start = async_start_method(method);
    AsyncPublicFields fields{};
    const bool fields_readable = safe_async_fields(value, &fields);
    std::string async_id;
    std::string previous_async_id;
    bool reused = false;
    bool callback_wrapped = false;
    {
        std::lock_guard lock(state_mutex);
        auto existing = async_blocks.find(value);
        if (existing == async_blocks.end() || is_start) {
            if (existing != async_blocks.end() && is_start) {
                reused = true;
                previous_async_id = existing->second.id;
            }
            // XAsyncBlock storage is commonly reused.  If the previous
            // operation installed our thunk, restore the user's callback
            // before using this block as the new operation's baseline.
            if (existing != async_blocks.end() && existing->second.callback_wrapped &&
                fields.callback == reinterpret_cast<void *>(&async_completion_thunk)) {
                fields.callback = existing->second.original_callback;
                safe_set_async_callback(const_cast<XAsyncBlock *>(value), fields.callback);
            }
            AsyncState state;
            state.id = "async#" + std::to_string(next_async_id.fetch_add(1));
            state.first_call_id = call_id;
            state.start_ns = now_ns();
            state.started = is_start;
            state.context = fields.context;
            state.queue = fields.queue;
            state.original_callback = fields.callback;
            if (!no_wrap_async_callbacks && is_start && fields_readable && fields.callback && fields.callback != reinterpret_cast<void *>(&async_completion_thunk)) {
                state.callback_wrapped = safe_set_async_callback(const_cast<XAsyncBlock *>(value), reinterpret_cast<void *>(&async_completion_thunk));
                callback_wrapped = state.callback_wrapped;
            }
            async_id = state.id;
            async_blocks[value] = state;
        } else {
            async_id = existing->second.id;
            callback_wrapped = existing->second.callback_wrapped;
        }
    }
    Json event;
    event.string_value("event", is_start ? "async_start" : "async_observed");
    event.string_value("async_id", async_id);
    event.number("call_id", call_id);
    event.string_value("api", method);
    event.raw_value("async_block", pointer_json(value, "async"));
    event.raw_value("queue", pointer_json(fields.queue, "queue"));
    event.raw_value("context", pointer_json(fields.context, "context"));
    event.raw_value("callback", pointer_json(fields.callback, "callback"));
    event.boolean("fields_readable", fields_readable);
    event.boolean("callback_wrapped", callback_wrapped);
    event.boolean("reused", reused);
    if (reused) event.string_value("previous_async_id", previous_async_id);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("callbacks.jsonl", event.finish());
}

void RecordAsyncCompletionResult(std::uint64_t call_id, const XAsyncBlock *value, HRESULT completion_result)
{
    if (level == Level::Minimal || !value) return;
    std::string async_id;
    bool completed_by_callback = false;
    std::uint64_t completion_timestamp_ns = 0;
    {
        std::lock_guard lock(state_mutex);
        auto found = async_blocks.find(value);
        if (found == async_blocks.end()) return;
        if (found->second.completed) return;
        found->second.completed = true;
        found->second.completion_result = completion_result;
        found->second.completion_call_id = call_id;
        async_id = found->second.id;
        completed_by_callback = found->second.completed_by_callback;
        completion_timestamp_ns = found->second.completion_timestamp_ns;
    }
    Json event;
    event.string_value("event", "async_complete");
    event.string_value("async_id", async_id);
    event.number("call_id", call_id);
    event.string_value("hresult", HResultHex(completion_result));
    event.string_value("hresult_name", HResultName(completion_result));
    event.boolean("completed_by_callback", completed_by_callback);
    if (completion_timestamp_ns) event.number("completion_timestamp_ns", completion_timestamp_ns);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("callbacks.jsonl", event.finish());
}

void RecordAsyncCompletionCallback(std::uint64_t callback_id, const XAsyncBlock *value)
{
    if (!callback_id || !value || level == Level::Minimal) return;
    std::string async_id;
    const auto completion_timestamp_ns = now_ns();
    {
        std::lock_guard lock(state_mutex);
        auto found = async_blocks.find(value);
        if (found == async_blocks.end()) return;
        found->second.callback_invoked = true;
        found->second.completed_by_callback = true;
        found->second.completion_timestamp_ns = completion_timestamp_ns;
        async_id = found->second.id;
    }
    Json event;
    event.string_value("event", "async_completion_callback");
    event.string_value("async_id", async_id);
    event.number("callback_id", callback_id);
    event.boolean("completed_by_callback", true);
    event.number("completion_timestamp_ns", completion_timestamp_ns);
    event.number("timestamp_ns", completion_timestamp_ns);
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("callbacks.jsonl", event.finish());
}

void RecordAsyncCallEnd(std::uint64_t call_id, const XAsyncBlock *value, HRESULT api_result, bool has_api_result)
{
    if (!call_id || !value || level == Level::Minimal) return;
    const std::string method = method_for_call(call_id);
    std::string lowered = method;
    std::transform(lowered.begin(), lowered.end(), lowered.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    const auto ends_with = [&lowered](const char *suffix) {
        const std::size_t length = std::strlen(suffix);
        return lowered.size() >= length && lowered.compare(lowered.size() - length, length, suffix) == 0;
    };
    std::string async_id;
    bool emit_cancel = false;
    bool emit_status = false;
    bool emit_result = false;
    if (lowered.find("cancel") != std::string::npos) emit_cancel = true;
    if (lowered == "xasyncgetstatus" && has_api_result && api_result != E_PENDING) emit_status = true;
    // Result-size/count methods are preparation queries, not result
    // retrievals.  Only the ABI's XAsyncGetResult and public *Result/*ResultCount
    // methods represent consumption of the completed async result.
    if (has_api_result && (lowered == "xasyncgetresult" || ends_with("result") || ends_with("resultcount")))
        emit_result = true;
    {
        std::lock_guard lock(state_mutex);
        auto found = async_blocks.find(value);
        if (found == async_blocks.end()) return;
        async_id = found->second.id;
        if (emit_cancel) {
            if (has_api_result && FAILED(api_result)) emit_cancel = false;
            else if (found->second.cancelled) emit_cancel = false;
            else found->second.cancelled = true;
        }
        if (emit_status && found->second.completed) emit_status = false;
    }
    if (emit_cancel) {
        Json event;
        event.string_value("event", "async_cancel");
        event.string_value("async_id", async_id);
        event.number("call_id", call_id);
        event.string_value("hresult", HResultHex(api_result));
        event.number("timestamp_ns", now_ns());
        event.number("wall_timestamp_ns", wall_now_ns());
        emit("callbacks.jsonl", event.finish());
    }
    if (emit_result) {
        Json event;
        event.string_value("event", "async_result");
        event.string_value("async_id", async_id);
        event.number("call_id", call_id);
        event.string_value("api", method);
        event.string_value("hresult", HResultHex(api_result));
        event.string_value("hresult_name", HResultName(api_result));
        event.number("timestamp_ns", now_ns());
        event.number("wall_timestamp_ns", wall_now_ns());
        emit("callbacks.jsonl", event.finish());
    }
    if (emit_status || (emit_result && has_api_result && api_result != E_PENDING))
        RecordAsyncCompletionResult(call_id, value, api_result);
}

void __stdcall async_completion_thunk(XAsyncBlock *value) noexcept
{
    void *original = nullptr;
    AsyncPublicFields fields{};
    try {
        {
            std::lock_guard lock(state_mutex);
            auto found = async_blocks.find(value);
            if (found != async_blocks.end()) {
                original = found->second.original_callback;
                found->second.callback_invoked = true;
            }
        }
        RecursionGuard guard;
        if (guard.entered()) {
            safe_async_fields(value, &fields);
            const auto callback_id = BeginCallbackInvocation(
                "XAsyncCompletionRoutine", original, fields.context, fields.queue);
            RecordAsyncCompletionCallback(callback_id, value);
            RecordCallbackPointer(callback_id, "asyncBlock", value);
            EndCallbackInvocation(callback_id);
        }
    } catch (...) {
        // The target callback still runs below even if observation fails.
    }
    if (original) {
        safe_set_async_callback(value, original);
        try {
            reinterpret_cast<void(WINAPI *)(XAsyncBlock *)>(original)(value);
        } catch (...) {
            // A callback is outside the tracer's ownership; do not let an
            // unexpected C++ exception escape through the C ABI thunk.
        }
    }
}

void RecordRuntimeLoad(HMODULE module, const std::wstring &path, const std::string &version, const std::string &sha256, const std::string &exports_json)
{
    if (!initialized) return;
    const std::string safe_path = basename_utf8(path);
    const std::string safe_exports = exports_json.empty() ? "[]" : exports_json;
    {
        std::lock_guard lock(state_mutex);
        runtime_path = safe_path;
        runtime_version = version;
        runtime_sha256 = sha256;
        runtime_exports = safe_exports;
        write_metadata();
    }
    Json event;
    event.string_value("event", "runtime_load");
    event.string_value("path", safe_path);
    event.string_value("file_version", version);
    event.string_value("sha256", sha256);
    event.raw_value("exports", safe_exports);
    event.raw_value("module", pointer_json(module, "module"));
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("sideeffects.jsonl", event.finish());
}

void RecordRuntimeExportHook(const char *name, bool installed)
{
    Json event;
    event.string_value("event", "runtime_export_hook");
    event.string_value("kind", "runtime_export_hook");
    event.string_value("name", name ? name : "");
    event.boolean("installed", installed);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("sideeffects.jsonl", event.finish());
}

void RecordRuntimeExportCall(const char *name, HRESULT result)
{
    Json event;
    event.string_value("event", "runtime_export_call");
    event.string_value("name", name ? name : "");
    event.string_value("hresult", HResultHex(result));
    event.string_value("hresult_name", HResultName(result));
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordRuntimeErrorReport(HRESULT reported_error, const char *context, HRESULT result)
{
    bool readable = true;
    bool truncated = false;
    const std::string text = safe_read_ansi_string(context, 4096, &readable, &truncated);
    Json event;
    event.string_value("event", "runtime_export_call");
    event.string_value("name", "XErrorReport");
    event.string_value("reported_error", HResultHex(reported_error));
    event.string_value("reported_error_name", HResultName(reported_error));
    event.string_value("hresult", HResultHex(result));
    event.string_value("hresult_name", HResultName(result));
    // Error-report context is diagnostic text supplied by the target and may
    // contain a path, URL, account name, or token even though its parameter
    // name is generic.  Preserve correlation without publishing the text.
    event.raw_value("context", redact(text, "runtime-error-context"));
    event.boolean("context_readable", readable);
    event.boolean("context_truncated", truncated);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordSideEffect(const char *kind, const char *operation, const wchar_t *target,
    std::int64_t result_code, bool succeeded, std::uint64_t bytes)
{
    if (!initialized || level == Level::Minimal) return;
    bool readable = true;
    bool truncated = false;
    const std::string target_text = safe_read_utf16_string(target, 4096, &readable, &truncated);
    const std::string lowered_kind = [&] {
        std::string value = kind ? kind : "unknown";
        std::transform(value.begin(), value.end(), value.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
        return value;
    }();
    const bool sensitive = contains_secret_name(target_text.c_str()) || is_identity_name(target_text.c_str());
    Json target_json;
    target_json.boolean("null", target == nullptr);
    target_json.boolean("readable", readable);
    target_json.boolean("truncated", truncated);
    target_json.number("length", target_text.size());
    if (!target_text.empty()) {
        target_json.string_value("sha256", sha256_text(target_text));
        if (sensitive || lowered_kind == "network" || lowered_kind == "registry") {
            target_json.raw_value("name", redact(target_text, "side-effect-target"));
        } else {
            // Keep enough information to group file activity without
            // publishing user-profile paths or complete registry keys.
            const std::wstring wide_target = wide(target_text);
            target_json.string_value("name", basename_utf8(wide_target));
        }
    }
    Json event;
    event.string_value("event", "side_effect");
    event.string_value("kind", lowered_kind);
    event.string_value("operation", operation ? operation : "");
    event.raw_value("target", target_json.finish());
    event.signed_number("result_code", result_code);
    event.boolean("succeeded", succeeded);
    event.number("bytes", bytes);
    event.number("thread_id", GetCurrentThreadId());
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("sideeffects.jsonl", event.finish());
}

bool IsTraceOutputPath(const wchar_t *path) noexcept
{
    if (!path || session_directory.empty()) return false;
    try {
        bool readable = true;
        const std::wstring value = wide(safe_read_utf16_string(path, 4096, &readable, nullptr));
        if (!readable || value.empty()) return false;
        std::wstring root = session_directory.wstring();
        auto lower_path = [](std::wstring value) {
            std::transform(value.begin(), value.end(), value.begin(), [](wchar_t ch) { return static_cast<wchar_t>(towlower(ch)); });
            std::replace(value.begin(), value.end(), L'/', L'\\');
            return value;
        };
        const auto lowered_value = lower_path(value);
        const auto lowered_root = lower_path(root);
        return lowered_value == lowered_root ||
            (lowered_value.size() > lowered_root.size() &&
             lowered_value.compare(0, lowered_root.size(), lowered_root) == 0 &&
             lowered_value[lowered_root.size()] == L'\\');
    } catch (...) {
        return false;
    }
}

void RecordInitialization(const char *name, ULONG gdk_version, ULONG gaming_services_version, char mode, const void *options, HRESULT result)
{
    Json event;
    event.string_value("event", "initialize");
    event.string_value("method", name ? name : "");
    event.number("gdk_version", gdk_version);
    event.number("gaming_services_version", gaming_services_version);
    event.number("mode", static_cast<unsigned char>(mode));
    event.raw_value("options", pointer_json(options, "options"));
    event.string_value("hresult", HResultHex(result));
    event.string_value("hresult_name", HResultName(result));
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordQueryApi(const GUID *clsid, const GUID *iid, void *out, HRESULT result, const void *returned_interface)
{
    Json event;
    event.string_value("event", "query_interface");
    event.string_value("api", "QueryApiImpl");
    if (clsid) event.string_value("clsid", GuidString(*clsid));
    if (iid) event.string_value("iid", GuidString(*iid));
    event.raw_value("out", pointer_json(out, "out"));
    event.raw_value("returned_interface", pointer_json(returned_interface, "interface"));
    event.string_value("hresult", HResultHex(result));
    event.string_value("hresult_name", HResultName(result));
    event.number("thread_id", GetCurrentThreadId());
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordQueryInterface(const void *self, const GUID *iid, void *out, HRESULT result, const void *returned_interface)
{
    Json event;
    event.string_value("event", "query_interface");
    event.string_value("api", "IUnknown::QueryInterface");
    event.raw_value("self", pointer_json(self, "interface"));
    if (iid) event.string_value("iid", GuidString(*iid));
    event.raw_value("out", pointer_json(out, "out"));
    event.raw_value("returned_interface", pointer_json(returned_interface, "interface"));
    event.string_value("hresult", HResultHex(result));
    event.string_value("hresult_name", HResultName(result));
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordIUnknown(const char *method, const void *self, ULONG result)
{
    Json event;
    event.string_value("event", "call");
    event.string_value("interface", "IUnknown");
    event.string_value("method", method ? method : "");
    event.raw_value("object", pointer_json(self, "interface"));
    event.number("result", result);
    event.number("thread_id", GetCurrentThreadId());
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordObjectCreated(const void *interface_pointer, const char *iid, std::uint32_t vtable_slots)
{
    Json event;
    event.string_value("event", "object_create");
    event.raw_value("interface", pointer_json(interface_pointer, "interface"));
    event.string_value("iid", iid ? iid : "");
    event.number("vtable_slots", vtable_slots);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordObjectUpgraded(const void *interface_pointer, const char *iid, std::uint32_t vtable_slots)
{
    Json event;
    event.string_value("event", "object_upgrade");
    event.raw_value("interface", pointer_json(interface_pointer, "interface"));
    event.string_value("iid", iid ? iid : "");
    event.number("vtable_slots", vtable_slots);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordObjectReleased(const void *interface_pointer, ULONG ref_count)
{
    Json event;
    event.string_value("event", "object_release");
    event.raw_value("interface", pointer_json(interface_pointer, "interface"));
    event.number("ref_count", ref_count);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

void RecordUnknownSlot(const void *self, const char *iid, std::uint32_t slot)
{
    Json event;
    event.string_value("event", "unknown_slot_invoked");
    event.raw_value("self", pointer_json(self, "interface"));
    event.string_value("iid", iid ? iid : "");
    event.number("slot", slot);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("calls.jsonl", event.finish());
}

std::uint64_t BeginCallbackInvocation(const char *kind, const void *callback, const void *context, const void *queue)
{
    if (!initialized || level == Level::Minimal) return 0;
    const auto callback_id = next_callback_id.fetch_add(1);
    std::uint64_t registration_call_id = 0;
    const void *resolved_queue = queue;
    {
        std::lock_guard lock(state_mutex);
        for (auto it = callback_registrations.rbegin(); it != callback_registrations.rend(); ++it) {
            if (it->active && it->kind == (kind ? kind : "") && it->context == context && it->original == callback) {
                registration_call_id = it->registration_call_id;
                if (!resolved_queue) resolved_queue = it->queue;
                break;
            }
        }
    }
    Json event;
    event.string_value("event", "callback");
    event.string_value("phase", "invoke");
    event.number("callback_id", callback_id);
    event.string_value("kind", kind ? kind : "");
    event.raw_value("callback", pointer_json(callback, "callback"));
    event.raw_value("context", pointer_json(context, "context"));
    event.raw_value("queue", pointer_json(resolved_queue, "queue"));
    if (registration_call_id) event.number("registration_call_id", registration_call_id);
    event.number("thread_id", GetCurrentThreadId());
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("callbacks.jsonl", event.finish());
    return callback_id;
}

void RecordCallbackScalar(std::uint64_t callback_id, const char *name, std::uint64_t value, std::size_t width, bool is_signed)
{
    if (!callback_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "callback_argument");
    event.number("callback_id", callback_id);
    event.string_value("name", name ? name : "");
    event.string_value("value", "0x" + [&] { std::ostringstream out; out << std::hex << value; return out.str(); }());
    event.number("width", width);
    event.boolean("signed", is_signed);
    emit("callbacks.jsonl", event.finish());
}

void RecordCallbackText(std::uint64_t callback_id, const char *name, const char *value, bool sensitive)
{
    if (!callback_id || level == Level::Minimal) return;
    bool readable = true;
    bool truncated = false;
    const std::string text = safe_read_ansi_string(value, 16 * 1024, &readable, &truncated);
    Json event;
    event.string_value("event", "callback_argument");
    event.number("callback_id", callback_id);
    event.string_value("name", name ? name : "");
    if (sensitive || contains_secret_name(name)) event.raw_value("value", redact(text, "callback-secret"));
    else if (is_identity_name(name)) event.raw_value("value", pseudonym(text, "callback-identity"));
    else if (is_location_name(name)) event.raw_value("value", redact(text, "callback-location"));
    else event.string_value("value", text);
    event.boolean("readable", readable);
    event.boolean("truncated", truncated);
    emit("callbacks.jsonl", event.finish());
}

void RecordCallbackText(std::uint64_t callback_id, const char *name, const wchar_t *value, bool sensitive)
{
    if (!callback_id || level == Level::Minimal) return;
    bool readable = true;
    bool truncated = false;
    const std::string text = safe_read_utf16_string(value, 16 * 1024, &readable, &truncated);
    Json event;
    event.string_value("event", "callback_argument");
    event.number("callback_id", callback_id);
    event.string_value("name", name ? name : "");
    if (sensitive || contains_secret_name(name)) event.raw_value("value", redact(text, "callback-secret-wstring"));
    else if (is_identity_name(name)) event.raw_value("value", pseudonym(text, "callback-identity-wstring"));
    else if (is_location_name(name)) event.raw_value("value", redact(text, "callback-location-wstring"));
    else event.string_value("value", text);
    event.boolean("readable", readable);
    event.boolean("truncated", truncated);
    emit("callbacks.jsonl", event.finish());
}

void RecordCallbackPointer(std::uint64_t callback_id, const char *name, const void *value)
{
    if (!callback_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "callback_argument");
    event.number("callback_id", callback_id);
    event.string_value("name", name ? name : "");
    event.raw_value("value", pointer_json(value, "callback-argument"));
    emit("callbacks.jsonl", event.finish());
}

void EndCallbackInvocation(std::uint64_t callback_id)
{
    if (!callback_id || level == Level::Minimal) return;
    Json event;
    event.string_value("event", "callback");
    event.string_value("phase", "return");
    event.number("callback_id", callback_id);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("callbacks.jsonl", event.finish());
}

bool RegisterCallback(const char *kind, const void *callback, const void *context, const void *queue,
                      const void *wrapper, std::uint64_t registration_call_id) noexcept
{
    if (!callback || !wrapper) return false;
    std::string event_line;
    bool ambiguous = false;
    try {
        {
            std::lock_guard lock(state_mutex);
            for (const auto &registration : callback_registrations) {
                if (registration.active && registration.kind == (kind ? kind : "") &&
                    registration.context == context && registration.original != callback) {
                    ambiguous = true;
                    break;
                }
            }
        }
        const auto make_event = [&](bool is_ambiguous) {
            Json event;
            event.string_value("event", "callback");
            event.string_value("phase", "register");
            event.number("registration_call_id", registration_call_id);
            event.string_value("kind", kind ? kind : "");
            event.raw_value("callback", pointer_json(callback, "callback"));
            event.raw_value("wrapper", pointer_json(is_ambiguous ? nullptr : wrapper, "callback-wrapper"));
            event.raw_value("context", pointer_json(context, "context"));
            event.raw_value("queue", pointer_json(queue, "queue"));
            event.boolean("wrapped", !is_ambiguous);
            event.boolean("callback_wrap_ambiguous", is_ambiguous);
            event.number("timestamp_ns", now_ns());
            event.number("wall_timestamp_ns", wall_now_ns());
            return event.finish();
        };
        const bool event_ambiguous = ambiguous;
        event_line = make_event(event_ambiguous);
        if (!ambiguous) {
            std::lock_guard lock(state_mutex);
            // Recheck while holding the insertion lock.  A concurrent
            // registration may have made the pair ambiguous after the first
            // scan; in that case the original callback must remain untouched.
            for (const auto &registration : callback_registrations) {
                if (registration.active && registration.kind == (kind ? kind : "") &&
                    registration.context == context && registration.original != callback) {
                    ambiguous = true;
                    break;
                }
            }
            if (!ambiguous) {
                callback_registrations.push_back(CallbackRegistration{
                    kind ? kind : "", callback, context, queue, wrapper, registration_call_id, {}, true});
            }
        }
        if (ambiguous && !event_ambiguous)
            event_line = make_event(true);
    } catch (...) {
        return false;
    }
    try {
        emit("callbacks.jsonl", event_line);
    } catch (...) {
        // Registration has already been installed; keep the wrapper active
        // even if the best-effort event write cannot allocate.
    }
    return !ambiguous;
}

void RecordCallbackToken(std::uint64_t call_id, const void *token_storage, std::size_t token_size)
{
    if (!call_id || !token_storage) return;
    bool readable = true;
    const auto token = read_handle_value(token_storage, token_size, &readable);
    const std::string key = handle_key("XTaskQueueRegistrationToken", token);
    std::lock_guard lock(state_mutex);
    for (auto &registration : callback_registrations)
        if (registration.registration_call_id == call_id) registration.token_key = key;
}

void UnregisterCallback(std::uint64_t call_id, const void *token_storage, std::size_t token_size, bool success)
{
    if (!call_id || !token_storage || !success) return;
    bool readable = true;
    const auto token = read_handle_value(token_storage, token_size, &readable);
    const std::string key = handle_key("XTaskQueueRegistrationToken", token);
    std::string kind;
    {
        std::lock_guard lock(state_mutex);
        for (auto &registration : callback_registrations) {
            if (registration.active && registration.token_key == key) {
                registration.active = false;
                kind = registration.kind;
            }
        }
    }
    Json event;
    event.string_value("event", "callback");
    event.string_value("phase", "unregister");
    event.number("call_id", call_id);
    event.string_value("kind", kind);
    event.raw_value("token", redact(key, "registration-token"));
    event.boolean("readable", readable);
    event.number("timestamp_ns", now_ns());
    event.number("wall_timestamp_ns", wall_now_ns());
    emit("callbacks.jsonl", event.finish());
}

void *ResolveCallback(const char *kind, const void *context) noexcept
{
    std::lock_guard lock(state_mutex);
    const void *last_matching = nullptr;
    for (auto it = callback_registrations.rbegin(); it != callback_registrations.rend(); ++it) {
        if (it->kind != (kind ? kind : "") || it->context != context) continue;
        if (!last_matching) last_matching = it->original;
        if (it->active) return const_cast<void *>(it->original);
    }
    // A non-waiting unregister may race a final callback already queued on a
    // task queue.  Forwarding the last known callback is safer than silently
    // swallowing that callback at the ABI boundary.
    return const_cast<void *>(last_matching);
}

void RegisterWrappedInterface(void *interface_pointer, void **original_vtable, void **wrapped_vtable, const char *iid, std::uint32_t slots)
{
    if (!interface_pointer) return;
    std::lock_guard lock(state_mutex);
    auto found = interfaces.find(interface_pointer);
    if (found == interfaces.end()) {
        interfaces.emplace(interface_pointer, WrappedInterface{
            original_vtable, wrapped_vtable, iid ? iid : "", slots,
            iid ? std::vector<std::string>{iid} : std::vector<std::string>{}});
        return;
    }
    auto &entry = found->second;
    if (!entry.original_vtable) entry.original_vtable = original_vtable;
    if (!entry.wrapped_vtable) entry.wrapped_vtable = wrapped_vtable;
    if (slots >= entry.slots) entry.slots = slots;
    entry.iid = iid ? iid : "";
    if (iid && std::find(entry.observed_iids.begin(), entry.observed_iids.end(), iid) == entry.observed_iids.end())
        entry.observed_iids.emplace_back(iid);
}

bool InstallWrappedInterface(void *interface_pointer, void **original_vtable, void **wrapped_vtable, const char *iid, std::uint32_t slots)
{
    if (!interface_pointer || !original_vtable || !wrapped_vtable || !slots) return false;
    bool installed = false;
    {
        std::lock_guard lock(state_mutex);
        auto found = interfaces.find(interface_pointer);
        if (found == interfaces.end()) {
            interfaces.emplace(interface_pointer, WrappedInterface{
                original_vtable, wrapped_vtable, iid ? iid : "", slots,
                iid ? std::vector<std::string>{iid} : std::vector<std::string>{}});
            InterlockedExchangePointer(reinterpret_cast<PVOID volatile *>(interface_pointer), wrapped_vtable);
            installed = true;
        } else {
            auto &entry = found->second;
            if (iid && std::find(entry.observed_iids.begin(), entry.observed_iids.end(), iid) == entry.observed_iids.end())
                entry.observed_iids.emplace_back(iid);
            if (slots > entry.slots && entry.original_vtable == original_vtable) {
                if (entry.wrapped_vtable) {
                    try {
                        entry.retired_vtables.push_back(entry.wrapped_vtable);
                    } catch (...) {
                        return false;
                    }
                }
                entry.wrapped_vtable = wrapped_vtable;
                entry.slots = slots;
                entry.iid = iid ? iid : entry.iid;
                InterlockedExchangePointer(reinterpret_cast<PVOID volatile *>(interface_pointer), wrapped_vtable);
                installed = true;
            }
        }
    }
    return installed;
}

void UnregisterWrappedInterface(void *interface_pointer)
{
    std::lock_guard lock(state_mutex);
    auto it = interfaces.find(interface_pointer);
    if (it != interfaces.end()) {
        HeapFree(GetProcessHeap(), 0, it->second.wrapped_vtable);
        for (auto *retired : it->second.retired_vtables)
            HeapFree(GetProcessHeap(), 0, retired);
        interfaces.erase(it);
    }
}

void **OriginalVtable(void *interface_pointer) noexcept
{
    std::lock_guard lock(state_mutex);
    auto it = interfaces.find(interface_pointer);
    return it == interfaces.end() ? nullptr : it->second.original_vtable;
}

std::uint32_t WrappedSlots(void *interface_pointer) noexcept
{
    std::lock_guard lock(state_mutex);
    auto it = interfaces.find(interface_pointer);
    return it == interfaces.end() ? 0 : it->second.slots;
}

void ObserveWrappedInterface(void *interface_pointer, const char *iid)
{
    if (!interface_pointer) return;
    std::lock_guard lock(state_mutex);
    auto it = interfaces.find(interface_pointer);
    if (it == interfaces.end()) return;
    if (iid && std::find(it->second.observed_iids.begin(), it->second.observed_iids.end(), iid) == it->second.observed_iids.end())
        it->second.observed_iids.emplace_back(iid);
}

void *OriginalSlot(void *interface_pointer, std::uint32_t slot) noexcept
{
    std::lock_guard lock(state_mutex);
    auto it = interfaces.find(interface_pointer);
    if (it == interfaces.end() || !it->second.original_vtable || slot >= it->second.slots) return nullptr;
    return it->second.original_vtable[slot];
}

std::string GuidString(const GUID &guid)
{
    wchar_t buffer[64]{};
    if (!StringFromGUID2(guid, buffer, ARRAYSIZE(buffer))) return {};
    std::wstring value(buffer);
    if (value.size() >= 2 && value.front() == L'{' && value.back() == L'}') value = value.substr(1, value.size() - 2);
    return utf8(value);
}

std::string HResultHex(HRESULT result)
{
    std::ostringstream out;
    out << "0x" << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << static_cast<std::uint32_t>(result);
    return out.str();
}

std::string HResultName(HRESULT result)
{
    switch (static_cast<std::uint32_t>(result)) {
#define XGRTRACE_HRESULT_CASE(name, value) case value: return #name;
        XGRTRACE_KNOWN_HRESULTS(XGRTRACE_HRESULT_CASE)
#undef XGRTRACE_HRESULT_CASE
    default: break;
    }
    switch (result) {
    case S_OK: return "S_OK";
    case S_FALSE: return "S_FALSE";
    case E_NOTIMPL: return "E_NOTIMPL";
    case E_NOINTERFACE: return "E_NOINTERFACE";
    case E_POINTER: return "E_POINTER";
    case E_INVALIDARG: return "E_INVALIDARG";
    case E_ACCESSDENIED: return "E_ACCESSDENIED";
    case E_PENDING: return "E_PENDING";
    case E_ABORT: return "E_ABORT";
    default: return "UNKNOWN_HRESULT";
    }
}

std::string Sha256File(const std::wstring &path)
{
    return file_sha256(std::filesystem::path(path));
}

std::string PointerId(const void *pointer, const char *kind)
{
    if (!pointer) return {};
    std::lock_guard lock(state_mutex);
    auto found = pointer_ids.find(pointer);
    if (found != pointer_ids.end()) return found->second;
    std::string id = std::string(kind ? kind : "object") + "#" + std::to_string(next_pointer_id.fetch_add(1));
    pointer_ids.emplace(pointer, id);
    return id;
}

} // namespace xgrtrace::trace
