// SPDX-License-Identifier: MIT
#include <windows.h>

#include "runtime_hooks.h"
#include "trace_core.h"

#include <thread>

namespace {
HANDLE bootstrap_thread = nullptr;

DWORD WINAPI bootstrap(void *)
{
    try {
        xgrtrace::trace::LoadProcessConfiguration();
        xgrtrace::trace::Initialize();
        xgrtrace::dll::StartRuntimeMonitor();
    } catch (...) {
        // The tracer is optional; initialization failure must not affect the game.
    }
    return 0;
}

} // namespace

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(instance);
        xgrtrace::trace::LoadProcessConfiguration();
        bootstrap_thread = CreateThread(nullptr, 0, bootstrap, nullptr, 0, nullptr);
    } else if (reason == DLL_PROCESS_DETACH) {
        try {
            xgrtrace::dll::StopRuntimeMonitor();
            xgrtrace::trace::Shutdown();
        } catch (...) {
        }
        if (bootstrap_thread) {
            CloseHandle(bootstrap_thread);
            bootstrap_thread = nullptr;
        }
    }
    return TRUE;
}
