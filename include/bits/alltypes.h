#ifndef _BITS_ALLTYPES_H_
#define _BITS_ALLTYPES_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if __WORDSIZE == 32
#define _Addr int
#endif

#if __WORDSIZE == 64
#define _Addr long
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _BITS_ALLTYPES_H_

