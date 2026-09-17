// Copyright (c) 2026 Xodus interoperability contributors.
// SPDX-License-Identifier: MIT
#pragma once

#include <windows.h>

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <type_traits>

struct XAsyncBlock;

namespace xgrtrace::trace {

enum class Level : std::uint32_t { Minimal, Normal, Verbose };

enum class ArgumentKind : std::uint32_t {
    Scalar,
    Pointer,
    Out,
    String,
    StringSensitive,
    OutputString,
    Handle,
};

enum class OutputEncoding : std::uint32_t {
    Binary,
    Ansi,
    Utf16,
};

class RecursionGuard {
public:
    RecursionGuard() noexcept;
    ~RecursionGuard();
    RecursionGuard(const RecursionGuard &) = delete;
    RecursionGuard &operator=(const RecursionGuard &) = delete;
    bool entered() const noexcept { return entered_; }

private:
    bool entered_;
};

void Initialize();
void Shutdown();
void LoadProcessConfiguration() noexcept;
bool IsInitialized() noexcept;
Level CurrentLevel() noexcept;

std::uint64_t BeginCall(const char *iid, std::uint32_t slot, const char *method, const void *self);
void EndCallVoid(std::uint64_t call_id);
void EndCallHResult(std::uint64_t call_id, HRESULT result);
void EndCallScalar(std::uint64_t call_id, std::uint64_t result, std::size_t width, bool is_signed);
void RecordScalarNumber(std::uint64_t call_id, const char *name, std::uint64_t value, std::size_t width, bool is_signed);
void RecordInputString(std::uint64_t call_id, const char *name, const char *value, ArgumentKind kind);
void RecordInputString(std::uint64_t call_id, const char *name, const wchar_t *value, ArgumentKind kind);
void RecordInputStringArray(std::uint64_t call_id, const char *name, const void *values, std::size_t count, std::size_t maximum_length, bool utf16, bool sensitive);
void RecordInputStringArrayFromCountPointer(std::uint64_t call_id, const char *name, const void *values, const void *count_storage, std::size_t count_width, std::size_t maximum_length, bool utf16, bool sensitive);
void RecordInputBuffer(std::uint64_t call_id, const char *name, const void *value, std::size_t size, const char *type, bool sensitive);
void RecordOutputString(std::uint64_t call_id, const char *name, const void *value, ArgumentKind kind);
void RecordOutputBuffer(std::uint64_t call_id, const char *name, const void *value, std::size_t capacity, const void *used, std::size_t used_width, std::size_t unit_size, const char *type, OutputEncoding encoding, bool sensitive);
void RecordOutputStringArray(std::uint64_t call_id, const char *name, const void *values, std::size_t count, std::size_t maximum_length, bool utf16, bool sensitive);
void RecordOutputValue(std::uint64_t call_id, const char *name, const void *value, std::size_t size, const char *type, bool sensitive);
void RecordOutputPointeeValue(std::uint64_t call_id, const char *name, const void *storage, std::size_t pointer_width, std::size_t pointee_size, const char *type, bool sensitive);
void RecordOutputScalarValue(std::uint64_t call_id, const char *name, const void *value, std::size_t width, bool is_signed, const char *type, bool sensitive);
void RecordOutputPointerValue(std::uint64_t call_id, const char *name, const void *storage, std::size_t width, const char *type, bool sensitive);
void RecordOutputHandleValue(std::uint64_t call_id, const char *name, const void *storage, std::size_t width, const char *type);
void RecordPointer(std::uint64_t call_id, const char *name, const void *value, ArgumentKind kind);
void RecordOutputPointer(std::uint64_t call_id, const char *name, const void *value);
void RecordOpaqueHandle(std::uint64_t call_id, const char *name, const void *value);
void RecordHandleArgument(std::uint64_t call_id, const char *name, const void *value, std::size_t width, const char *type);
void RecordAsyncArgument(std::uint64_t call_id, const char *name, const void *value);
void RecordScalarText(std::uint64_t call_id, const char *name, const char *value);
void RecordScalarFloat(std::uint64_t call_id, const char *name, double value);
void RecordAsyncBlock(std::uint64_t call_id, const char *name, const XAsyncBlock *value);
void RecordAsyncCallEnd(std::uint64_t call_id, const XAsyncBlock *value, HRESULT api_result, bool has_api_result);
void RecordAsyncCompletionResult(std::uint64_t call_id, const XAsyncBlock *value, HRESULT completion_result);
void RecordAsyncCompletionCallback(std::uint64_t callback_id, const XAsyncBlock *value);

template <typename T>
void RecordScalar(std::uint64_t call_id, const char *name, const T &value)
{
    using Value = std::remove_cv_t<std::remove_reference_t<T>>;
    if constexpr (std::is_floating_point_v<Value>)
        RecordScalarFloat(call_id, name, static_cast<double>(value));
    else if constexpr (std::is_same_v<Value, bool>)
        RecordScalarText(call_id, name, value ? "true" : "false");
    else if constexpr (std::is_enum_v<Value>)
        RecordScalarNumber(call_id, name, static_cast<std::uint64_t>(value), sizeof(Value), std::is_signed_v<std::underlying_type_t<Value>>);
    else if constexpr (std::is_integral_v<Value>)
        RecordScalarNumber(call_id, name, static_cast<std::uint64_t>(value), sizeof(Value), std::is_signed_v<Value>);
    else
        RecordPointer(call_id, name, reinterpret_cast<const void *>(&value), ArgumentKind::Pointer);
}

template <typename T>
void EndCall(std::uint64_t call_id, const T &value)
{
    using Value = std::remove_cv_t<std::remove_reference_t<T>>;
    if constexpr (std::is_same_v<Value, HRESULT>)
        EndCallHResult(call_id, value);
    else if constexpr (std::is_floating_point_v<Value>)
        EndCallScalar(call_id, static_cast<std::uint64_t>(value), sizeof(Value), true);
    else if constexpr (std::is_enum_v<Value>)
        EndCallScalar(call_id, static_cast<std::uint64_t>(value), sizeof(Value), std::is_signed_v<std::underlying_type_t<Value>>);
    else if constexpr (std::is_integral_v<Value>)
        EndCallScalar(call_id, static_cast<std::uint64_t>(value), sizeof(Value), std::is_signed_v<Value>);
    else
        EndCallScalar(call_id, 0, sizeof(Value), false);
}

void RecordRuntimeLoad(HMODULE module, const std::wstring &path, const std::string &version, const std::string &sha256, const std::string &exports_json);
void RecordRuntimeExportHook(const char *name, bool installed);
void RecordRuntimeExportCall(const char *name, HRESULT result);
void RecordRuntimeErrorReport(HRESULT reported_error, const char *context, HRESULT result);
void RecordSideEffect(const char *kind, const char *operation, const wchar_t *target, std::int64_t result_code, bool succeeded, std::uint64_t bytes = 0);
bool IsTraceOutputPath(const wchar_t *path) noexcept;
void RecordInitialization(const char *name, ULONG gdk_version, ULONG gaming_services_version, char mode, const void *options, HRESULT result);
void RecordQueryApi(const GUID *clsid, const GUID *iid, void *out, HRESULT result, const void *returned_interface);
void RecordQueryInterface(const void *self, const GUID *iid, void *out, HRESULT result, const void *returned_interface);
void RecordIUnknown(const char *method, const void *self, ULONG result);
void RecordObjectCreated(const void *interface_pointer, const char *iid, std::uint32_t vtable_slots);
void RecordObjectUpgraded(const void *interface_pointer, const char *iid, std::uint32_t vtable_slots);
void RecordObjectReleased(const void *interface_pointer, ULONG ref_count);
void RecordUnknownSlot(const void *self, const char *iid, std::uint32_t slot);
std::uint64_t BeginCallbackInvocation(const char *kind, const void *callback, const void *context, const void *queue);
void RecordCallbackScalar(std::uint64_t callback_id, const char *name, std::uint64_t value, std::size_t width, bool is_signed);
void RecordCallbackText(std::uint64_t callback_id, const char *name, const char *value, bool sensitive);
void RecordCallbackText(std::uint64_t callback_id, const char *name, const wchar_t *value, bool sensitive);
void RecordCallbackPointer(std::uint64_t callback_id, const char *name, const void *value);
void EndCallbackInvocation(std::uint64_t callback_id);
bool RegisterCallback(const char *kind, const void *callback, const void *context, const void *queue, const void *wrapper, std::uint64_t registration_call_id) noexcept;
void UnregisterCallback(std::uint64_t call_id, const void *token_storage, std::size_t token_size, bool success);
void RecordCallbackToken(std::uint64_t call_id, const void *token_storage, std::size_t token_size);
void *ResolveCallback(const char *kind, const void *context) noexcept;

template <typename Callback>
Callback *WrapCallback(std::uint64_t call_id, const char *kind, Callback *callback, const void *context, const void *queue, Callback *wrapper)
{
    if (call_id && callback && wrapper && RegisterCallback(kind, reinterpret_cast<const void *>(callback), context, queue,
                                                           reinterpret_cast<const void *>(wrapper), call_id))
        return wrapper;
    return callback;
}

template <typename Callback>
Callback WrapCallbackValue(std::uint64_t call_id, const char *kind, Callback callback, const void *context, const void *queue, Callback wrapper)
{
    if (call_id && callback && wrapper && RegisterCallback(kind, reinterpret_cast<const void *>(callback), context, queue,
                                                           reinterpret_cast<const void *>(wrapper), call_id))
        return wrapper;
    return callback;
}

template <typename T>
bool CopyFromTarget(const T *source, T *destination) noexcept
{
    if (!source || !destination) return false;
    __try {
        std::memcpy(destination, source, sizeof(T));
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

// Per-instance wrapper bookkeeping. The original vtable is never changed.
void RegisterWrappedInterface(void *interface_pointer, void **original_vtable, void **wrapped_vtable, const char *iid, std::uint32_t slots);
bool InstallWrappedInterface(void *interface_pointer, void **original_vtable, void **wrapped_vtable, const char *iid, std::uint32_t slots);
void UnregisterWrappedInterface(void *interface_pointer);
void **OriginalVtable(void *interface_pointer) noexcept;
void *OriginalSlot(void *interface_pointer, std::uint32_t slot) noexcept;

std::uint32_t WrappedSlots(void *interface_pointer) noexcept;
void ObserveWrappedInterface(void *interface_pointer, const char *iid);

template <typename T>
void RecordOutputObject(std::uint64_t call_id, const char *name, const T *value, const char *type, bool sensitive = false)
{
    if constexpr (std::is_pointer_v<T>) {
        RecordOutputPointerValue(call_id, name, value, sizeof(T), type, sensitive);
    } else if constexpr (std::is_enum_v<T>) {
        RecordOutputScalarValue(call_id, name, value, sizeof(T), std::is_signed_v<std::underlying_type_t<T>>, type, sensitive);
    } else if constexpr (std::is_integral_v<T>) {
        RecordOutputScalarValue(call_id, name, value, sizeof(T), std::is_signed_v<T>, type, sensitive);
    } else if constexpr (std::is_floating_point_v<T>) {
        RecordOutputScalarValue(call_id, name, value, sizeof(T), true, type, sensitive);
    } else {
        RecordOutputValue(call_id, name, value, sizeof(T), type, sensitive);
    }
}

template <typename T>
void RecordOutputHandleObject(std::uint64_t call_id, const char *name, const T *value, const char *type)
{
    RecordOutputHandleValue(call_id, name, value, sizeof(T), type);
}

template <typename T>
void RecordHandleArgumentValue(std::uint64_t call_id, const char *name, const T &value, const char *type)
{
    RecordHandleArgument(call_id, name, &value, sizeof(T), type);
}

template <typename T>
void RecordCallbackArgument(std::uint64_t callback_id, const char *name, const T &value)
{
    using Value = std::remove_cv_t<std::remove_reference_t<T>>;
    if constexpr (std::is_same_v<Value, char *> || std::is_same_v<Value, const char *>)
        RecordCallbackText(callback_id, name, value, false);
    else if constexpr (std::is_same_v<Value, wchar_t *> || std::is_same_v<Value, const wchar_t *>)
        RecordCallbackText(callback_id, name, value, false);
    else if constexpr (std::is_pointer_v<Value>)
        RecordCallbackPointer(callback_id, name, reinterpret_cast<const void *>(value));
    else if constexpr (std::is_enum_v<Value>)
        RecordCallbackScalar(callback_id, name, static_cast<std::uint64_t>(value), sizeof(Value), std::is_signed_v<std::underlying_type_t<Value>>);
    else if constexpr (std::is_integral_v<Value>)
        RecordCallbackScalar(callback_id, name, static_cast<std::uint64_t>(value), sizeof(Value), std::is_signed_v<Value>);
    else if constexpr (std::is_floating_point_v<Value>)
        RecordCallbackScalar(callback_id, name, static_cast<std::uint64_t>(value), sizeof(Value), true);
    else
        RecordCallbackPointer(callback_id, name, reinterpret_cast<const void *>(&value));
}

std::string GuidString(const GUID &guid);
std::string HResultName(HRESULT result);
std::string HResultHex(HRESULT result);
std::string Sha256File(const std::wstring &path);
std::string PointerId(const void *pointer, const char *kind = "object");

} // namespace xgrtrace::trace
