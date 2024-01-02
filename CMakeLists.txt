cmake_minimum_required(VERSION 3.10)

set (VERBOSE 1)
set (CMAKE_VERBOSE_MAKEFILE on)

set (WAMR_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

# Minimal configuration for Genode
set (WAMR_BUILD_PLATFORM genode)
set (WAMR_BUILD_TARGET X86_64)
set (WAMR_BUILD_LIBC_BUILTIN 0)
set (WAMR_BUILD_INTERP 1)
set (WAMR_BUILD_AOT 0)

# my bit :)
set (WAMR_BUILD_BULK_MEMORY 1)
set (WAMR_BUILD_FAST_INTERP 0)
add_definitions(-D__GENODE__=1)

# include (${WAMR_ROOT_DIR}/build-scripts/runtime_lib.cmake)
# add_library(vmlib ${WAMR_RUNTIME_LIB_SOURCE})

include(${WAMR_ROOT_DIR}/product-mini/platforms/genode/CMakeLists.txt)
