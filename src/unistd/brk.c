#include <stddef.h>
#include <unistd.h>

#include <matter/page_size.h>


extern unsigned char __heap_base;
void *break_pointer = &__heap_base;

int brk(void *addr) {
  break_pointer = addr;
  return 0;
}

#ifdef __wasm__

void * sbrk(ssize_t increment) {
  size_t current_pages = __builtin_wasm_memory_size(0);
  void   *heap_limit   = (void *)(current_pages * PAGE_SIZE);

  void *ret = break_pointer;
  break_pointer += increment;

  if (break_pointer > heap_limit) {
    __builtin_wasm_memory_grow(0, ((break_pointer - heap_limit) / PAGE_SIZE) + 1);
  }

  return ret;
}

#endif // __wasm__
