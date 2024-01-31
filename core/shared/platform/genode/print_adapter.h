#include <ph_io.h>

#define snprintf(s, n, fmt, ...) ph_snprintf(s, n, fmt, __VA_ARGS__) 

static inline int vsnprintf(char *s, size_t n, const char *format, va_list arg) { return ph_vsnprintf(s, n, format, arg); }