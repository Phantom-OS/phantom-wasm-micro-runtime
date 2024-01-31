#include <ph_malloc.h>

static inline void *os_malloc(unsigned size) { return ph_malloc(size); }

static inline void *os_realloc(void *ptr, unsigned size) { return ph_realloc(ptr, size); }

static inline void os_free(void *ptr) { ph_free(ptr); }
