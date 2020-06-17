#ifndef _STDDEF_H_
#define _STDDEF_H_

#include <bits/alltypes.h>

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

typedef unsigned _Addr size_t;
typedef _Addr ssize_t;
typedef _Addr ptrdiff_t;

#endif // _STDDEF_H_
