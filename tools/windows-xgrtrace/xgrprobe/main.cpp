// SPDX-License-Identifier: MIT
#include <windows.h>
#include <objbase.h>

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using InitializeApiImplFn = HRESULT(WINAPI *)(ULONG, ULONG);
using InitializeApiImplExFn = HRESULT(WINAPI *)(ULONG, ULONG, char);
using InitializeApiImplEx2Fn = HRESULT(WINAPI *)(ULONG, ULONG, char, const void *);
using QueryApiImplFn = HRESULT(WINAPI *)(const GUID *, const GUID *, void **);
using DllCanUnloadNowFn = HRESULT(WINAPI *)();
using UninitializeApiImplFn = HRESULT(WINAPI *)();
using XErrorReportFn = HRESULT(WINAPI *)(HRESULT, const char *);
using ReleaseFn = ULONG(WINAPI *)(void *);
using QueueCreateFn = HRESULT(WINAPI *)(void *, std::uint32_t, std::uint32_t, void **);
using QueueDuplicateFn = HRESULT(WINAPI *)(void *, void *, void **);
using QueueDispatchFn = BOOLEAN(WINAPI *)(void *, void *, std::uint32_t, std::uint32_t);
using QueueCloseFn = void(WINAPI *)(void *, void *);
using QueueSubmitCallbackFn = HRESULT(WINAPI *)(void *, void *, std::uint32_t, void *, void (WINAPI *)(void *, BOOLEAN));
using AsyncGetStatusFn = HRESULT(WINAPI *)(void *, void *, BOOLEAN);
using AsyncGetResultSizeFn = HRESULT(WINAPI *)(void *, void *, SIZE_T *);
using AsyncGetResultFn = HRESULT(WINAPI *)(void *, void *, const void *, SIZE_T, void *, SIZE_T *);

constexpr std::uint32_t kXTaskQueueCreateSlot = 12;
constexpr std::uint32_t kXTaskQueueDuplicateHandleSlot = 15;
constexpr std::uint32_t kXTaskQueueDispatchSlot = 16;
constexpr std::uint32_t kXTaskQueueCloseHandleSlot = 17;
constexpr std::uint32_t kXTaskQueueSubmitCallbackSlot = 18;
constexpr std::uint32_t kXAsyncGetStatusSlot = 3;
constexpr std::uint32_t kXAsyncGetResultSizeSlot = 4;
constexpr std::uint32_t kXAsyncGetResultSlot = 11;

struct ProbeAsyncBlock {
    void *queue;
    void *context;
    void *callback;
    unsigned internal[sizeof(void *) * 4];
};

volatile LONG probe_callback_count = 0;

void WINAPI probe_queue_callback(void *, BOOLEAN)
{
    InterlockedIncrement(&probe_callback_count);
}

std::string guid_text(const GUID &guid)
{
    wchar_t buffer[64]{};
    StringFromGUID2(guid, buffer, ARRAYSIZE(buffer));
    std::wstring value(buffer);
    if (value.size() > 1 && value.front() == L'{' && value.back() == L'}') value = value.substr(1, value.size() - 2);
    int size = WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    std::string result(size, '\0');
    if (size) WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<int>(value.size()), result.data(), size, nullptr, nullptr);
    return result;
}

std::string hresult(HRESULT value)
{
    std::ostringstream out;
    out << "0x" << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << static_cast<ULONG>(value);
    return out.str();
}

int usage()
{
    std::wcerr << L"xgrprobe.exe --initialize [gdk-version] [gaming-services-version] [mode]\n"
                  L"xgrprobe.exe --query <clsid> <iid> [--before-init] [--repeat N]\n"
                  L"xgrprobe.exe --invalid-query [--before-init]\n"
                  L"xgrprobe.exe --queue [--before-init]\n"
                  L"xgrprobe.exe --async-invalid [--before-init]\n"
                  L"xgrprobe.exe --lifecycle [gdk-version] [gaming-services-version] [mode]\n"
                  L"xgrprobe.exe --exports\n";
    return 2;
}

void release_interface_safely(void *interface_pointer)
{
    if (!interface_pointer) return;
    __try {
        auto vtable = *reinterpret_cast<void ***>(interface_pointer);
        if (vtable && vtable[2]) reinterpret_cast<ReleaseFn>(vtable[2])(interface_pointer);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        // A probe must not turn a malformed third-party object into a crash.
    }
}

HRESULT call_query_safely(QueryApiImplFn query, const GUID *clsid, const GUID *iid, void **out, bool *faulted)
{
    if (faulted) *faulted = false;
    if (!query) return E_NOTIMPL;
    __try {
        return query(clsid, iid, out);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_noarg_safely(DllCanUnloadNowFn function, bool *faulted)
{
    if (faulted) *faulted = false;
    if (!function) return E_NOTIMPL;
    __try {
        return function();
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_initialize_safely(InitializeApiImplFn initialize, InitializeApiImplExFn initialize_ex,
    InitializeApiImplEx2Fn initialize_ex2, ULONG gdk, ULONG gs, char mode, bool *used_ex2, bool *faulted)
{
    if (used_ex2) *used_ex2 = initialize_ex2 != nullptr;
    if (faulted) *faulted = false;
    __try {
        return initialize_ex2 ? initialize_ex2(gdk, gs, mode, nullptr)
            : (initialize_ex ? initialize_ex(gdk, gs, mode) : (initialize ? initialize(gdk, gs) : E_NOTIMPL));
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_uninitialize_safely(UninitializeApiImplFn function, bool *faulted)
{
    if (faulted) *faulted = false;
    if (!function) return E_NOTIMPL;
    __try {
        return function();
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

bool get_vtable_slot_safely(void *interface_pointer, std::uint32_t slot, void **function, bool *faulted)
{
    if (function) *function = nullptr;
    if (faulted) *faulted = false;
    if (!interface_pointer || !function) return false;
    __try {
        void **vtable = *reinterpret_cast<void ***>(interface_pointer);
        if (!vtable) return false;
        *function = vtable[slot];
        return *function != nullptr;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return false;
    }
}

HRESULT call_queue_create_safely(void *interface_pointer, std::uint32_t work_mode,
                                 std::uint32_t completion_mode, void **queue, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (queue) *queue = nullptr;
    if (!get_vtable_slot_safely(interface_pointer, kXTaskQueueCreateSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return E_NOTIMPL;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<QueueCreateFn>(function)(interface_pointer, work_mode, completion_mode, queue);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_queue_duplicate_safely(void *interface_pointer, void *queue, void **duplicate, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (duplicate) *duplicate = nullptr;
    if (!get_vtable_slot_safely(interface_pointer, kXTaskQueueDuplicateHandleSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return E_NOTIMPL;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<QueueDuplicateFn>(function)(interface_pointer, queue, duplicate);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

BOOLEAN call_queue_dispatch_safely(void *interface_pointer, void *queue, std::uint32_t port,
                                   std::uint32_t timeout, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (!get_vtable_slot_safely(interface_pointer, kXTaskQueueDispatchSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return FALSE;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<QueueDispatchFn>(function)(interface_pointer, queue, port, timeout);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return FALSE;
    }
}

bool call_queue_close_safely(void *interface_pointer, void *queue, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (!get_vtable_slot_safely(interface_pointer, kXTaskQueueCloseHandleSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return false;
    }
    if (faulted) *faulted = false;
    __try {
        reinterpret_cast<QueueCloseFn>(function)(interface_pointer, queue);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return false;
    }
}

HRESULT call_queue_submit_safely(void *interface_pointer, void *queue, std::uint32_t port,
                                 void *context, void (WINAPI *callback)(void *, BOOLEAN), bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (!get_vtable_slot_safely(interface_pointer, kXTaskQueueSubmitCallbackSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return E_NOTIMPL;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<QueueSubmitCallbackFn>(function)(interface_pointer, queue, port, context, callback);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_async_status_safely(void *interface_pointer, ProbeAsyncBlock *async_block, BOOLEAN wait, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (!get_vtable_slot_safely(interface_pointer, kXAsyncGetStatusSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return E_NOTIMPL;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<AsyncGetStatusFn>(function)(interface_pointer, async_block, wait);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_async_result_size_safely(void *interface_pointer, ProbeAsyncBlock *async_block,
                                      SIZE_T *buffer_size, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (buffer_size) *buffer_size = 0;
    if (!get_vtable_slot_safely(interface_pointer, kXAsyncGetResultSizeSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return E_NOTIMPL;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<AsyncGetResultSizeFn>(function)(interface_pointer, async_block, buffer_size);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

HRESULT call_async_result_safely(void *interface_pointer, ProbeAsyncBlock *async_block, const void *identity,
                                 SIZE_T buffer_size, void *buffer, SIZE_T *buffer_used, bool *faulted)
{
    void *function = nullptr;
    bool slot_faulted = false;
    if (buffer_used) *buffer_used = 0;
    if (!get_vtable_slot_safely(interface_pointer, kXAsyncGetResultSlot, &function, &slot_faulted)) {
        if (faulted) *faulted = slot_faulted;
        return E_NOTIMPL;
    }
    if (faulted) *faulted = false;
    __try {
        return reinterpret_cast<AsyncGetResultFn>(function)(interface_pointer, async_block, identity,
                                                            buffer_size, buffer, buffer_used);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (faulted) *faulted = true;
        return E_FAIL;
    }
}

void print_result(const char *case_name, HRESULT result, bool faulted = false)
{
    std::cout << "{\"case\":\"" << case_name << "\",\"faulted\":"
              << (faulted ? "true" : "false") << ",\"hresult\":\"" << hresult(result) << "\"}\n";
}

int wmain(int argc, wchar_t **argv)
{
    if (argc < 2) return usage();
    HMODULE runtime = LoadLibraryW(L"xgameruntime.dll");
    if (!runtime) {
        std::wcerr << L"Unable to load xgameruntime.dll: " << GetLastError() << L"\n";
        return 1;
    }
    auto initialize = reinterpret_cast<InitializeApiImplFn>(GetProcAddress(runtime, "InitializeApiImpl"));
    auto initialize_ex = reinterpret_cast<InitializeApiImplExFn>(GetProcAddress(runtime, "InitializeApiImplEx"));
    auto initialize_ex2 = reinterpret_cast<InitializeApiImplEx2Fn>(GetProcAddress(runtime, "InitializeApiImplEx2"));
    auto query = reinterpret_cast<QueryApiImplFn>(GetProcAddress(runtime, "QueryApiImpl"));
    auto can_unload = reinterpret_cast<DllCanUnloadNowFn>(GetProcAddress(runtime, "DllCanUnloadNow"));
    auto uninitialize = reinterpret_cast<UninitializeApiImplFn>(GetProcAddress(runtime, "UninitializeApiImpl"));
    auto error_report = reinterpret_cast<XErrorReportFn>(GetProcAddress(runtime, "XErrorReport"));
    HRESULT result = E_NOTIMPL;
    bool initialized = false;

    auto run_initialize = [&](ULONG gdk, ULONG gs, char mode) {
        bool faulted = false;
        bool used_ex2 = false;
        result = call_initialize_safely(initialize, initialize_ex, initialize_ex2, gdk, gs, mode, &used_ex2, &faulted);
        initialized = !faulted && SUCCEEDED(result);
        std::cout << "{\"case\":\"initialize\",\"gdk_version\":" << gdk
                  << ",\"gaming_services_version\":" << gs
                  << ",\"mode\":" << static_cast<unsigned>(static_cast<unsigned char>(mode))
                  << ",\"used_ex2\":" << (used_ex2 ? "true" : "false")
                  << ",\"faulted\":" << (faulted ? "true" : "false")
                  << ",\"hresult\":\"" << hresult(result) << "\"}\n";
        return result;
    };

    if (std::wstring(argv[1]) == L"--initialize") {
        ULONG gdk = argc > 2 ? wcstoul(argv[2], nullptr, 0) : 0;
        ULONG gs = argc > 3 ? wcstoul(argv[3], nullptr, 0) : 0;
        char mode = argc > 4 ? static_cast<char>(wcstol(argv[4], nullptr, 0)) : 0;
        run_initialize(gdk, gs, mode);
    } else if (std::wstring(argv[1]) == L"--query" && argc >= 4) {
        GUID clsid{}, iid{};
        if (FAILED(CLSIDFromString(argv[2], &clsid)) || FAILED(CLSIDFromString(argv[3], &iid))) {
            std::wcerr << L"Both CLSID and IID must be GUIDs.\n";
            FreeLibrary(runtime);
            return 2;
        }
        bool before_init = false;
        unsigned repeat = 1;
        for (int index = 4; index < argc; ++index) {
            if (std::wstring(argv[index]) == L"--before-init") before_init = true;
            else if (std::wstring(argv[index]) == L"--repeat" && index + 1 < argc)
                repeat = std::max<unsigned>(1u, static_cast<unsigned>(wcstoul(argv[++index], nullptr, 0)));
        }
        if (!before_init) run_initialize(0, 0, 0);
        void *interface_pointer = nullptr;
        for (unsigned iteration = 0; iteration < repeat; ++iteration) {
            interface_pointer = nullptr;
            bool faulted = false;
            result = call_query_safely(query, &clsid, &iid, &interface_pointer, &faulted);
            std::cout << "{\"case\":\"query\",\"iteration\":" << iteration
                      << ",\"before_init\":" << (before_init ? "true" : "false")
                      << ",\"clsid\":\"" << guid_text(clsid)
                      << "\",\"iid\":\"" << guid_text(iid)
                      << "\",\"returned_nonnull\":" << (interface_pointer ? "true" : "false")
                      << ",\"faulted\":" << (faulted ? "true" : "false")
                      << ",\"hresult\":\"" << hresult(result) << "\"}\n";
            release_interface_safely(interface_pointer);
        }
    } else if (std::wstring(argv[1]) == L"--invalid-query") {
        bool before_init = false;
        for (int index = 2; index < argc; ++index) if (std::wstring(argv[index]) == L"--before-init") before_init = true;
        if (!before_init) run_initialize(0, 0, 0);
        GUID zero{};
        void *out = nullptr;
        bool faulted = false;
        bool any_faulted = false;
        result = call_query_safely(query, nullptr, nullptr, nullptr, &faulted);
        any_faulted = any_faulted || faulted;
        print_result("invalid-query-null-all", result, faulted);
        result = call_query_safely(query, &zero, &zero, nullptr, &faulted);
        any_faulted = any_faulted || faulted;
        print_result("invalid-query-null-out", result, faulted);
        result = call_query_safely(query, &zero, &zero, &out, &faulted);
        any_faulted = any_faulted || faulted;
        std::cout << "{\"case\":\"invalid-query-zero-guids\",\"returned_nonnull\":"
                  << (out ? "true" : "false") << ",\"faulted\":" << (faulted ? "true" : "false")
                  << ",\"hresult\":\"" << hresult(result) << "\"}\n";
        release_interface_safely(out);
        // These calls intentionally exercise invalid arguments. Their API
        // HRESULTs are the probe output, not the probe process status.
        result = any_faulted ? E_FAIL : S_OK;
    } else if (std::wstring(argv[1]) == L"--queue" || std::wstring(argv[1]) == L"--async-invalid") {
        const bool queue_probe = std::wstring(argv[1]) == L"--queue";
        bool before_init = false;
        for (int index = 2; index < argc; ++index) {
            if (std::wstring(argv[index]) == L"--before-init") before_init = true;
        }
        if (!before_init) run_initialize(0, 0, 0);

        GUID threading_clsid{}, threading_iid{};
        CLSIDFromString(L"{073b7dcb-1fcf-4030-94be-e3c9eb623428}", &threading_clsid);
        CLSIDFromString(L"{073b7dcb-1fcf-4030-94be-e3c9eb623428}", &threading_iid);
        void *threading = nullptr;
        bool query_faulted = false;
        HRESULT query_result = call_query_safely(query, &threading_clsid, &threading_iid, &threading, &query_faulted);
        std::cout << "{\"case\":\"threading-query\",\"probe\":\""
                  << (queue_probe ? "queue" : "async-invalid")
                  << "\",\"before_init\":" << (before_init ? "true" : "false")
                  << ",\"returned_nonnull\":" << (threading ? "true" : "false")
                  << ",\"faulted\":" << (query_faulted ? "true" : "false")
                  << ",\"hresult\":\"" << hresult(query_result) << "\"}\n";
        bool any_faulted = query_faulted;

        if (queue_probe && threading) {
            void *queue = nullptr;
            bool faulted = false;
            HRESULT create_result = call_queue_create_safely(threading, 0, 0, &queue, &faulted);
            any_faulted = any_faulted || faulted;
            std::cout << "{\"case\":\"queue-create\",\"returned_nonnull\":"
                      << (queue ? "true" : "false") << ",\"faulted\":"
                      << (faulted ? "true" : "false") << ",\"hresult\":\""
                      << hresult(create_result) << "\"}\n";

            void *duplicate = nullptr;
            if (queue) {
                faulted = false;
                HRESULT duplicate_result = call_queue_duplicate_safely(threading, queue, &duplicate, &faulted);
                any_faulted = any_faulted || faulted;
                std::cout << "{\"case\":\"queue-duplicate\",\"returned_nonnull\":"
                          << (duplicate ? "true" : "false") << ",\"faulted\":"
                          << (faulted ? "true" : "false") << ",\"hresult\":\""
                          << hresult(duplicate_result) << "\"}\n";

                probe_callback_count = 0;
                faulted = false;
                HRESULT submit_result = call_queue_submit_safely(threading, queue, 0, nullptr,
                                                                  probe_queue_callback, &faulted);
                any_faulted = any_faulted || faulted;
                std::cout << "{\"case\":\"queue-submit-callback\",\"faulted\":"
                          << (faulted ? "true" : "false") << ",\"hresult\":\""
                          << hresult(submit_result) << "\"}\n";

                faulted = false;
                BOOLEAN dispatched = call_queue_dispatch_safely(threading, queue, 0, 0, &faulted);
                any_faulted = any_faulted || faulted;
                std::cout << "{\"case\":\"queue-dispatch\",\"dispatched\":"
                          << (dispatched ? "true" : "false") << ",\"callback_count\":"
                          << probe_callback_count << ",\"faulted\":" << (faulted ? "true" : "false") << "}\n";
            }

            if (duplicate) {
                faulted = false;
                bool closed = call_queue_close_safely(threading, duplicate, &faulted);
                any_faulted = any_faulted || faulted;
                std::cout << "{\"case\":\"queue-close-duplicate\",\"closed\":"
                          << (closed ? "true" : "false") << ",\"faulted\":"
                          << (faulted ? "true" : "false") << "}\n";
            }
            if (queue) {
                faulted = false;
                bool closed = call_queue_close_safely(threading, queue, &faulted);
                any_faulted = any_faulted || faulted;
                std::cout << "{\"case\":\"queue-close\",\"closed\":"
                          << (closed ? "true" : "false") << ",\"faulted\":"
                          << (faulted ? "true" : "false") << "}\n";
            }
        } else if (!queue_probe && threading) {
            ProbeAsyncBlock invalid_block{};
            SIZE_T buffer_size = 0;
            SIZE_T buffer_used = 0;
            unsigned char one_byte[1]{};
            bool faulted = false;

            HRESULT status_null = call_async_status_safely(threading, nullptr, FALSE, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("async-status-null", status_null, faulted);

            faulted = false;
            HRESULT status_block = call_async_status_safely(threading, &invalid_block, FALSE, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("async-status-zero-block", status_block, faulted);

            faulted = false;
            HRESULT size_null = call_async_result_size_safely(threading, nullptr, &buffer_size, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("async-result-size-null-block", size_null, faulted);

            faulted = false;
            HRESULT size_block = call_async_result_size_safely(threading, &invalid_block, nullptr, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("async-result-size-null-output", size_block, faulted);

            faulted = false;
            HRESULT result_null = call_async_result_safely(threading, nullptr, nullptr, 0, nullptr, &buffer_used, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("async-result-null-block", result_null, faulted);

            faulted = false;
            HRESULT result_block = call_async_result_safely(threading, &invalid_block, nullptr, sizeof(one_byte),
                                                            one_byte, nullptr, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("async-result-zero-block", result_block, faulted);
        }

        release_interface_safely(threading);
        result = any_faulted ? E_FAIL : S_OK;
    } else if (std::wstring(argv[1]) == L"--lifecycle") {
        ULONG gdk = argc > 2 ? wcstoul(argv[2], nullptr, 0) : 0;
        ULONG gs = argc > 3 ? wcstoul(argv[3], nullptr, 0) : 0;
        char mode = argc > 4 ? static_cast<char>(wcstol(argv[4], nullptr, 0)) : 0;
        run_initialize(gdk, gs, mode);
        bool any_faulted = false;
        if (can_unload) {
            bool faulted = false;
            const HRESULT unload_result = call_noarg_safely(can_unload, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("dll-can-unload-after-init", unload_result, faulted);
        }
        if (uninitialize && initialized) {
            bool faulted = false;
            result = call_uninitialize_safely(uninitialize, &faulted);
            any_faulted = any_faulted || faulted;
            std::cout << "{\"case\":\"uninitialize\",\"called\":true,\"faulted\":"
                      << (faulted ? "true" : "false") << ",\"hresult\":\"" << hresult(result) << "\"}\n";
            initialized = !faulted && SUCCEEDED(result) ? false : initialized;
        } else {
            std::cout << "{\"case\":\"uninitialize\",\"called\":false}\n";
        }
        if (can_unload) {
            bool faulted = false;
            const HRESULT unload_result = call_noarg_safely(can_unload, &faulted);
            any_faulted = any_faulted || faulted;
            print_result("dll-can-unload-after-uninit", unload_result, faulted);
        }
        if (any_faulted) result = E_FAIL;
    } else if (std::wstring(argv[1]) == L"--exports") {
        std::cout << "{\"case\":\"exports\",\"DllCanUnloadNow\":" << (can_unload ? "true" : "false")
                  << ",\"InitializeApiImpl\":" << (initialize ? "true" : "false")
                  << ",\"InitializeApiImplEx\":" << (initialize_ex ? "true" : "false")
                  << ",\"InitializeApiImplEx2\":" << (initialize_ex2 ? "true" : "false")
                  << ",\"QueryApiImpl\":" << (query ? "true" : "false")
                  << ",\"UninitializeApiImpl\":" << (uninitialize ? "true" : "false")
                  << ",\"XErrorReport\":" << (error_report ? "true" : "false") << "}\n";
        result = S_OK;
    } else {
        FreeLibrary(runtime);
        return usage();
    }
    FreeLibrary(runtime);
    return FAILED(result) ? 1 : 0;
}
