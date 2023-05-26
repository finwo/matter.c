#ifndef _STDARG_H_
#define _STDARG_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef __builtin_va_list va_list;
typedef __builtin_va_list __isoc_va_list;

#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v)     __builtin_va_end(v)
#define va_arg(v,l)   __builtin_va_arg(v,l)
#define va_copy(d,s)  __builtin_va_copy(d,s)

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _STDARG_H_
