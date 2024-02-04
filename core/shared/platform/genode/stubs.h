#ifndef GENODE_STUBS_H
#define GENODE_STUBS_H

#include <stdarg.h>

// struct timespec {
//     long tv_sec;
//     long tv_nsec;
// };

// ################ JUST DECLARED ##################

// These 4 functions (including strtoul() below) are only used in `wasm_application_execute_func` function
// As long as we don't use it, these can be left alone 

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

// these are for built-in libc feature
inline static int atoi(const char *str) {}
inline static void*   memchr(void*, int, size_t) {}
inline static int 	strncasecmp(const char *s1, const char *s2, size_t len) {}
inline static size_t 	strspn(const char *s, const char *accept) {}
inline static int isgraph(int c) {}
inline static int isalnum(int c) {}
inline static size_t strcspn(const char *s, const char *reject) {}
inline static unsigned long int strtoul(const char *nptr, char **endptr, int base) {}

#endif // GENODE_STUBS_H
