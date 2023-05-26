#ifndef _MATTER_PAGE_SIZE_H_
#define _MATTER_PAGE_SIZE_H_

#define PAGE_SIZE (4*1024)

#ifdef __wasm__
#undef PAGE_SIZE
#define PAGE_SIZE (64*1024)
#endif

#endif
