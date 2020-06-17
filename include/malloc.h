#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <stddef.h>

void *malloc(size_t n);
void free(void *p);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nelem, size_t elsize);

#endif // _MALLOC_H_
