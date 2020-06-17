#ifndef _STRING_MEMSET_C_
#define _STRING_MEMSET_C_

#include <string.h>

void * memset (void *dest, int val, size_t len) {
  unsigned char *ptr = dest;
  while (len-- > 0)
    *ptr++ = val;
  return dest;
}

#endif // _STRING_MEMSET_C_
