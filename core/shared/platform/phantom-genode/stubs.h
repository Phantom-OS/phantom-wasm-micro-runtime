#ifndef GENODE_STUBS_H
#define GENODE_STUBS_H

#include <ph_string.h>
#include <ph_time.h>
#include <errno.h>
#include <kernel/mutex.h>

// ################ JUST DECLARED ##################

// These 4 functions are only used in `wasm_application_execute_func` function
// As long as we don't use it, these can be left alone 

unsigned long int strtoul(const char *nptr, char **endptr, int base);

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


#endif // GENODE_STUBS_H
