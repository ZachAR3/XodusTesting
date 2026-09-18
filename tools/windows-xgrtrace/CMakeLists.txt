cmake_minimum_required(VERSION 3.22)
project(xgrtrace LANGUAGES CXX)

option(XGRTRACE_BUILD_MARKER "Build the marker helper" ON)
set(XGRTRACE_DETOURS_ROOT "" CACHE PATH "Local Microsoft Detours checkout; not vendored")
set(XGRTRACE_GDK_ABI_HEADER "" CACHE STRING "Local public GDK umbrella header name or path")
set(XGRTRACE_GDK_INCLUDE_DIR "" CACHE PATH "Local public GDK include directory")
set(XGRTRACE_GDK_LIBRARY_DIR "" CACHE PATH "Local public GDK x64 library directory")

if (XGRTRACE_GDK_ABI_HEADER)
    if (IS_ABSOLUTE "${XGRTRACE_GDK_ABI_HEADER}" OR EXISTS "${XGRTRACE_GDK_ABI_HEADER}")
        file(TO_CMAKE_PATH "${XGRTRACE_GDK_ABI_HEADER}" XGRTRACE_GDK_ABI_HEADER_NORMALIZED)
        set(XGRTRACE_GDK_ABI_INCLUDE "#include \"${XGRTRACE_GDK_ABI_HEADER_NORMALIZED}\"")
    else()
        set(XGRTRACE_GDK_ABI_INCLUDE "#include <${XGRTRACE_GDK_ABI_HEADER}>")
    endif()
else()
    set(XGRTRACE_GDK_ABI_INCLUDE "#error \"Set XGRTRACE_GDK_ABI_HEADER to a local public GDK ABI umbrella header.\"")
endif()
configure_file(generated/xgrtrace_gdk_abi.h.in ${CMAKE_CURRENT_BINARY_DIR}/xgrtrace_gdk_abi.h @ONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_definitions(WIN32_LEAN_AND_MEAN NOMINMAX _WIN32_WINNT=0x0A00)

set(XGRTRACE_HAS_DETOURS 0)
if (XGRTRACE_DETOURS_ROOT)
    find_path(DETOURS_INCLUDE_DIR detours.h PATHS ${XGRTRACE_DETOURS_ROOT}/src NO_DEFAULT_PATH)
    find_library(DETOURS_LIBRARY detours PATHS ${XGRTRACE_DETOURS_ROOT}/lib.X64 NO_DEFAULT_PATH)
    if (DETOURS_INCLUDE_DIR AND DETOURS_LIBRARY)
        set(XGRTRACE_HAS_DETOURS 1)
    endif()
endif()

add_library(xgrtrace-dll SHARED
    xgrtrace-dll/dllmain.cpp
    xgrtrace-dll/runtime_hooks.cpp
    trace-common/trace_core.cpp
    generated/interface_metadata.cpp
    generated/wrappers.cpp
)
target_compile_definitions(xgrtrace-dll PRIVATE XGRTRACE_HAS_DETOURS=${XGRTRACE_HAS_DETOURS} _GAMING_DESKTOP=1)
target_include_directories(xgrtrace-dll PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/trace-common
    ${CMAKE_CURRENT_SOURCE_DIR}/xgrtrace-dll
)
if (XGRTRACE_GDK_INCLUDE_DIR)
    target_include_directories(xgrtrace-dll PRIVATE ${XGRTRACE_GDK_INCLUDE_DIR})
endif()
if (XGRTRACE_GDK_LIBRARY_DIR)
    target_link_directories(xgrtrace-dll PRIVATE ${XGRTRACE_GDK_LIBRARY_DIR})
endif()
if (DETOURS_INCLUDE_DIR)
    target_include_directories(xgrtrace-dll PRIVATE ${DETOURS_INCLUDE_DIR})
    target_link_libraries(xgrtrace-dll PRIVATE ${DETOURS_LIBRARY})
endif()
target_link_libraries(xgrtrace-dll PRIVATE bcrypt shlwapi version advapi32 ole32)

add_executable(xgrtrace-launch xgrtrace-launch/main.cpp)
target_compile_definitions(xgrtrace-launch PRIVATE _WIN32_WINNT=0x0A00)
target_include_directories(xgrtrace-launch PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/trace-common
)
target_link_libraries(xgrtrace-launch PRIVATE advapi32 psapi)

add_executable(xgrprobe xgrprobe/main.cpp)
target_link_libraries(xgrprobe PRIVATE ole32)

if (XGRTRACE_BUILD_MARKER)
    add_executable(xgrtrace-marker scripts/marker.cpp)
endif()

message(STATUS "xgrtrace Detours support: ${XGRTRACE_HAS_DETOURS}")
if (NOT XGRTRACE_GDK_ABI_HEADER)
    message(WARNING "Typed wrappers will not compile until XGRTRACE_GDK_ABI_HEADER points at local public GDK headers.")
endif()
