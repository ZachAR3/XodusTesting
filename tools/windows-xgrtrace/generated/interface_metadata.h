// Generated file. Do not edit by hand.
#pragma once
#include <cstdint>

namespace xgrtrace::generated {
struct MethodMetadata {
    const char *name;
    const char *iid;
    std::uint32_t slot;
    const char *signature;
    const char *implementation_state;
    const char *documentation_url;
    std::uintptr_t wrapper;
};
struct InterfaceMetadata {
    const char *name;
    const char *iid;
    const char *parent;
    std::uint32_t interface_index;
    std::uint32_t vtable_slots;
    const MethodMetadata *methods;
    std::uint32_t method_count;
};
const InterfaceMetadata *FindInterface(const char *iid);
const MethodMetadata *FindMethod(const InterfaceMetadata &metadata, std::uint32_t slot);
}
