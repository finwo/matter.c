#ifndef _UNISTD_BRK_C_
#define _UNISTD_BRK_C_

#include <unistd.h>

extern unsigned char __heap_base;
void *break_pointer = &__heap_base;

int brk(void *addr) {
  break_pointer = addr;
  return 0;
}

void * sbrk(ssize_t increment) {
  void *ret = break_pointer;
  break_pointer += increment;
  return ret;
}

#endif // _UNISTD_BRK_C_
