#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

typedef unsigned long size_t;
typedef signed long ssize_t;

#endif // _STDDEF_H_
