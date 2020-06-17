#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>

int memcmp (const void *str1, const void *str2, int count);
void *memcpy (void *dest, const void *src, size_t len);
void *memset (void *dest, int val, size_t len);

#endif // _STRING_H_
