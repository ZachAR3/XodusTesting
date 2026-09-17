// SPDX-License-Identifier: MIT
#pragma once

#include <windows.h>

#include <cstdint>
#include <string>

namespace xgrtrace::config {

constexpr std::uint32_t kVersion = 1;
constexpr std::uint32_t kPartialStart = 1u << 0;
constexpr std::uint32_t kNoWrapAsyncCallbacks = 1u << 1;

struct SharedConfiguration {
    std::uint32_t version;
    std::uint32_t flags;
    wchar_t trace_root[1024];
    wchar_t level[16];
};

inline std::wstring MappingName(DWORD pid)
{
    return L"Local\\XGRTRACE_CONFIG_" + std::to_wstring(pid);
}

} // namespace xgrtrace::config
