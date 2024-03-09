# Copyright (C) 2019 Intel Corporation.  All rights reserved.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

set (PLATFORM_SHARED_DIR ${CMAKE_CURRENT_LIST_DIR})

add_definitions(-DBH_PLATFORM_POSIX)
add_definitions(-D__FreeBSD__=5)


# SSP definitions (required by WASI)

# We will configure everything here, so disabling config file
# file: src/core/iwasm/libraries/libc-wasi/sandboxed-system-primitives/src/ssp_config.h
add_definitions(-DSSP_CONFIG_H)

# Updated ones
add_definitions(-DCONFIG_HAS_PREADV=0)
add_definitions(-DCONFIG_HAS_PWRITEV=0)
add_definitions(-DCONFIG_HAS_POSIX_FALLOCATE=0)
add_definitions(-DCONFIG_HAS_ARC4RANDOM_BUF=0)
add_definitions(-DCONFIG_HAS_GETRANDOM=1)
add_definitions(-DCONFIG_HAS_PTHREAD_CONDATTR_SETCLOCK=0)

# Defaults are also ok, but decided to fix this ones
add_definitions(-DCONFIG_HAS_CAP_ENTER=0)
add_definitions(-DCONFIG_HAS_CLOCK_NANOSLEEP=0)
add_definitions(-DCONFIG_HAS_FDATASYNC=0)
add_definitions(-DCONFIG_HAS_ISATTY=0)
add_definitions(-DCONFIG_HAS_PTHREAD_COND_TIMEDWAIT_RELATIVE_NP=0)
add_definitions(-DCONFIG_TLS_USE_GSBASE=0)
add_definitions(-DCONFIG_HAS_STD_ATOMIC=1)

# end SSP definitions



include_directories(${PLATFORM_SHARED_DIR})
include_directories(${PLATFORM_SHARED_DIR}/../include)

include (${CMAKE_CURRENT_LIST_DIR}/../common/math/platform_api_math.cmake)

file (GLOB_RECURSE source_all ${PLATFORM_SHARED_DIR}/*.c)

set (PLATFORM_SHARED_SOURCE ${source_all} ${PLATFORM_COMMON_MATH_SOURCE})

file (GLOB header ${PLATFORM_SHARED_DIR}/../include/*.h)
LIST (APPEND RUNTIME_LIB_HEADER_LIST ${header})
