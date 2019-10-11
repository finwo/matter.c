#ifndef _STDINT_H_
#define _STDINT_H_

#include <limits.h>

/* (u)int32_t */
#ifndef uint32_t
    #if (ULONG_MAX == 0xffffffffUL)
        typedef unsigned long uint32_t;
    #elif (UINT_MAX == 0xffffffffUL)
        typedef unsigned int uint32_t;
    #elif (USHRT_MAX == 0xffffffffUL)
        typedef unsigned short uint32_t;
    #endif
#endif
#ifndef int32_t
    #if (LONG_MAX == 0x7fffffffL)
        typedef signed long int32_t;
    #elif (INT_MAX == 0x7fffffffL)
        typedef signed int int32_t;
    #elif (SHRT_MAX == 0x7fffffffL)
        typedef signed short int32_t;
    #endif
#endif

/* (u)int64_t */
#ifndef uint64_t
    #if (ULLONG_MAX == 0xffffffffffffffffULL)
        typedef unsigned long long uint64_t;
    #elif (ULONG_MAX == 0xffffffffffffffffULL)
        typedef unsigned long uint64_t;
    #elif (UINT_MAX == 0xffffffffffffffffULL)
        typedef unsigned int uint64_t;
    #elif (USHRT_MAX == 0xffffffffffffffffULL)
        typedef unsigned short uint64_t;
    #endif
#endif
#ifndef int64_t
    #if (ULLONG_MAX == 0x7fffffffffffffffULL)
        typedef signed long long int64_t;
    #elif (ULONG_MAX == 0x7fffffffffffffffULL)
        typedef signed long int64_t;
    #elif (UINT_MAX == 0x7fffffffffffffffULL)
        typedef signed int int64_t;
    #elif (USHRT_MAX == 0x7fffffffffffffffULL)
        typedef signed short int64_t;
    #endif
#endif

#endif // _STDINT_H_
