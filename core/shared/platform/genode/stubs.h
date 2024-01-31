#ifndef GENODE_STUBS_H
#define GENODE_STUBS_H

#include <stdarg.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

// ################ JUST DECLARED ##################

// These 4 functions are only used in `wasm_application_execute_func` function
// As long as we don't use it, these can be left alone 
unsigned long int
strtoul(const char *nptr, char **endptr, int base);

unsigned long long int
strtoull(const char *nptr, char **endptr, int base);

double strtod(const char* str, char** endptr);

float strtof(const char* str, char** endptr);

// these two seem to only be used for AOT execution
void os_signal_unmask();
void os_sigreturn();

// ################## STUBBED ####################

// needed for assertions to terminate program. I'd say not essential
static inline void abort(void) {};

// WAMR says this one's optional (used for logging)
static inline korp_tid os_self_thread(void) { return 0; }

// Needed for logging and performance tracking. Can be implmeneted later
static inline uint64 os_time_get_boot_microsecond(void) { return 0; }

// Can return NULL for now, but WAMR recommends implementing it if possible
static inline uint8* os_thread_get_stack_boundary(void) { return NULL; }

// Currently mutexes only used in memory allocation (i think) [core/shared/mem-alloc/ems]
static inline int os_mutex_lock(korp_mutex *mutex) { return 0; }
static inline int os_mutex_unlock(korp_mutex *mutex) { return 0; }
static inline int os_mutex_init(korp_mutex *mutex) { return 0; }
static inline int os_mutex_destroy(korp_mutex *mutex) { return 0; }

#endif // GENODE_STUBS_H
