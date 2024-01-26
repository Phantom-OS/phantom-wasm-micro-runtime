/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

// Fixing signals.h error with __size_t
// #include <sys/cdefs.h>
// #include <machine/_types.h>

// #include <inttypes.h>
#include <stdint.h>
//#include <stdbool.h>
#include <assert.h>
// #include <time.h>
// #include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
//#include <pthread.h>
//#include <phantom_threads.h>
//#include <phantom_sync.h>
// #include <signal.h>
//#include <semaphore.h>
#include <limits.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
//#include <poll.h>
//#include <sched.h>
#include <errno.h>
//#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/mman.h>
//#include <sys/time.h>
// #include <sys/timeb.h>
//#include <sys/uio.h>
#include <sys/ioctl.h>
// #include <sys/socket.h>
//#include <sys/resource.h>
#include "string_adapter.h"
#include "stubs.h"
#include <kernel/config.h>

// Have to be defined last since defines empty macro __size_t (but why???)
// #include <stddef.h>

#include "genode_missing_types.h"
// #include "wasi_missing.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef BH_PLATFORM_LINUX
#define BH_PLATFORM_LINUX
#endif

/* Stack size of applet threads's native part.  */
#define BH_APPLET_PRESERVED_STACK_SIZE (32 * 1024)

/* Default thread priority */
#define BH_THREAD_DEFAULT_PRIORITY 0

// typedef pthread_t korp_tid;
// typedef pthread_mutex_t korp_mutex;
// typedef pthread_cond_t korp_cond;
// typedef pthread_t korp_thread;

// extern struct phantom_thread;
// extern struct phantom_mutex_impl;
// extern struct phantom_cond_impl;

typedef int phantom_thread;
struct phantom_mutex_impl { int _placeholder; };
struct phantom_cond_impl { int _placeholder; };

typedef phantom_thread korp_tid;
typedef phantom_thread korp_thread;
typedef struct phantom_mutex_impl korp_mutex;
typedef struct phantom_cond_impl korp_cond;

#if WASM_DISABLE_HW_BOUND_CHECK == 0
#if defined(BUILD_TARGET_X86_64) \
    || defined(BUILD_TARGET_AMD_64) \
    || defined(BUILD_TARGET_AARCH64)

//#include <setjmp.h>

#define OS_ENABLE_HW_BOUND_CHECK

#define os_thread_local_attribute __thread

// typedef jmp_buf korp_jmpbuf;

typedef struct stub_jmpbuf { int _placeholder; } korp_jmpbuf;

#define os_setjmp setjmp
#define os_longjmp longjmp
#define os_alloca alloca

#define os_getpagesize getpagesize

typedef void (*os_signal_handler)(void *sig_addr);

int os_signal_init(os_signal_handler handler);

void os_signal_destroy();

void os_signal_unmask();

void os_sigreturn();

static inline korp_tid os_self_thread(void) { return 0; }

static inline uint64 os_time_get_boot_microsecond(void) { return 0; }

static inline uint8* os_thread_get_stack_boundary(void) { return NULL; }

static inline void * os_malloc(unsigned size) { return 0; }

static inline void * os_realloc(void *ptr, unsigned size) { return 0; }

static inline void os_free(void *ptr) { }

// Currently mutexes only used in memory allocation (i think) [core/shared/mem-alloc/ems]
static inline int os_mutex_lock(korp_mutex *mutex) { return 0; }
static inline int os_mutex_unlock(korp_mutex *mutex) { return 0; }
static inline int os_mutex_init(korp_mutex *mutex) { return 0; }
static inline int os_mutex_destroy(korp_mutex *mutex) { return 0; }

#endif /* end of BUILD_TARGET_X86_64/AMD_64/AARCH64 */
#endif /* end of WASM_DISABLE_HW_BOUND_CHECK */

#ifdef __cplusplus
}
#endif

#endif /* end of _PLATFORM_INTERNAL_H */

