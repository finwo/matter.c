#ifndef _MALLOC_C_
#define _MALLOC_C_

#include <malloc.h>
#include <stddef.h>

extern unsigned char __heap_base;

unsigned char *bump_pointer = &__heap_base;

unsigned char *heap_start = &__heap_base;
unsigned char *heap_end   = &__heap_base;
unsigned int isize      = sizeof(unsigned int);
unsigned int hsize      = (2 * sizeof(unsigned int));

// TODO: realloc
// TODO: free

void * malloc(int n) {
  unsigned char *r     = heap_start;

  unsigned int *size = NULL;
  unsigned int *used = NULL;

  // Loop through known blocks
  while(r < heap_end) {
    size = (void*)r;
    used = (void*)(r+isize);

    // In-use = skip
    if (*used) {
      r += *size;
      continue;
    }

    // Too small = skip
    if ((*size) < (n + hsize)) {
      r += *size;
      continue;
    }

    // Take this block
    *used = n;
    return (void*)(r + hsize);
  }

  // Something went wrong
  if (r < heap_end) {
    return NULL;
  }

  // Build a new block
  size  = (void*)r;
  used  = (void*)(r+isize);
  *size = n + hsize;
  *used = n;
  heap_end = r + n + hsize;
  return (void*)(r + hsize);
}

void free(void *p) {
  unsigned int *used = p - isize;
  *used = 0;
}

#endif // _MALLOC_C_
