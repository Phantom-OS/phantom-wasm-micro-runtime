#ifndef GENODE_STUBS_H
#define GENODE_STUBS_H

#include <ph_string.h>
#include <ph_time.h>
#include <errno.h>
#include <kernel/mutex.h>

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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
static inline int 	strncasecmp(const char *s1, const char *s2, size_t len) {}
static inline size_t 	strspn(const char *s, const char *accept) {}
static inline int isgraph(int c) {}
static inline int isalnum(int c) {}
static inline size_t strcspn(const char *s, const char *reject) {}
static inline unsigned long int strtoul(const char *nptr, char **endptr, int base) {}
#pragma GCC diagnostic pop
#warning Unimplemented string functions

#endif // GENODE_STUBS_H
