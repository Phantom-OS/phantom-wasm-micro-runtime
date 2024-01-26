#ifndef GENODE_STUBS_H
#define GENODE_STUBS_H

#include <stdarg.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

unsigned long int
strtoul(const char *nptr, char **endptr, int base);

unsigned long long int
strtoull(const char *nptr, char **endptr, int base);

double strtod (const char* str, char** endptr);

float strtof (const char* str, char** endptr);

static inline int snprintf ( char* s, size_t n, const char * format, ... ) { return -1; }

int vsnprintf (char * s, size_t n, const char * format, va_list arg );

static inline void abort(void) {};

#endif // GENODE_STUBS_H
