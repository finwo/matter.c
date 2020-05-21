#ifndef _MEMCPY_C_
#define _MEMCPY_C_

#include <string.h>

void * memcpy (void *dest, const void *src, int len) {
  char *d = dest;
  const char *s = src;
  while (len--) {
    *d++ = *s++;
  }
  return dest;
}

#endif // _MEMCPY_C_
