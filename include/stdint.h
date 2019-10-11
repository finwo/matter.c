#ifndef _STDINT_H_
#define _STDINT_H_

#include <limits.h>

/* (u)int8_t */
#if (UINT_MAX == 0xffU)
  typedef unsigned int uint8_t;
  typedef signed   int int8_t;
#elif (USHRT_MAX == 0xffU)
  typedef unsigned short uint8_t;
  typedef signed   short int8_t;
#elif (UCHAR_MAX == 0xffU)
  typedef unsigned char uint8_t;
  typedef signed   char int8_t;
#endif

/* (u)int16_t */
#if (UINT_MAX == 0xffffU)
  typedef unsigned int uint16_t;
  typedef signed   int int16_t;
#elif (USHRT_MAX == 0xffffU)
  typedef unsigned short uint16_t;
  typedef signed   short int16_t;
#endif

/* (u)int32_t */
#if (ULONG_MAX == 0xffffffffUL)
  typedef unsigned long uint32_t;
  typedef signed   long int32_t;
#elif (UINT_MAX == 0xffffffffUL)
  typedef unsigned int uint32_t;
  typedef signed   int int32_t;
#elif (USHRT_MAX == 0xffffffffUL)
  typedef unsigned short uint32_t;
  typedef signed   short int32_t;
#endif

/* (u)int64_t */
#if (ULLONG_MAX == 0xffffffffffffffffULL)
  typedef unsigned long long uint64_t;
  typedef signed   long long int64_t;
#elif (ULONG_MAX == 0xffffffffffffffffULL)
  typedef unsigned long uint64_t;
  typedef signed   long int64_t;
#elif (UINT_MAX == 0xffffffffffffffffULL)
  typedef unsigned int uint64_t;
  typedef signed   int int64_t;
#elif (USHRT_MAX == 0xffffffffffffffffULL)
  typedef unsigned short uint64_t;
  typedef signed   short int64_t;
#endif

/* The ISO C99 standard specifies that in C++ implementations these
   should only be defined if explicitly requested.  */
#if !defined __cplusplus || defined __STDC_CONSTANT_MACROS

/* Signed.  */
# define INT8_C(c)	c
# define INT16_C(c)	c
# define INT32_C(c)	c
# if __WORDSIZE == 64
#  define INT64_C(c)	c ## L
# else
#  define INT64_C(c)	c ## LL
# endif

/* Unsigned.  */
# define UINT8_C(c)	c
# define UINT16_C(c)	c
# define UINT32_C(c)	c ## U
# if __WORDSIZE == 64
#  define UINT64_C(c)	c ## UL
# else
#  define UINT64_C(c)	c ## ULL
# endif

/* Maximal type.  */
# if __WORDSIZE == 64
#  define INTMAX_C(c)	c ## L
#  define UINTMAX_C(c)	c ## UL
# else
#  define INTMAX_C(c)	c ## LL
#  define UINTMAX_C(c)	c ## ULL
# endif

#endif	/* C++ && constant macros */

#endif // _STDINT_H_
