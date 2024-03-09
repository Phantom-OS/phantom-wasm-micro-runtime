#ifndef GENODE_STRING_ADAPTER_H
#define GENODE_STRING_ADAPTER_H

#include <ph_string.h>

// Probably crucial for WAMR
static inline size_t 	strlen(const char *string) { return ph_strlen(string); }
static inline int 	    strcmp(const char *s1, const char *s2) { return ph_strcmp(s1, s2); }
static inline int 	    memcmp(const void *s1v, const void *s2v, size_t size) { return ph_memcmp(s1v, s2v, size); }
static inline void*	    memmove(void *dst0, const void *src0, size_t length) { return ph_memmove(dst0, src0, length); }
static inline void*	    memcpy(void *dst0, const void *src0, size_t length) { return ph_memcpy(dst0, src0, length); }
static inline void*	    memset(void *dst0, int c0, size_t length) { return ph_memset(dst0, c0, length); }

#endif // GENODE_STRING_ADAPTER_H