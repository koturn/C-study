#pragma once
/*!
 * @brief Problem03 header file
 * @author  koturn 0;
 * @file    problem03.h
 * @version 0.1
 */


#include <stdio.h>
#include <string.h>

// Macros for inline-directive under various environmets
#ifndef __cplusplus  // In language-C
#  if defined(_MSC_VER)           // In Visual C++,
#    define inline      __inline  // 'inline' and '__inline__' aren't available
#    define __inline__  __inline  // but '__inline' is.
#  elif !defined(__GNUC__) && __STDC_VERSION__ < 199901L
#    define inline                // If 'inline' isn't available, remove 'inline'
#    define __inline              // as well as '__inline'.
#  endif
#endif
// Macros for restrict-qualifier under various environmets
#if _MSC_VER >= 1400                // In Visual C++ (after Visual C++ 2005),
#  define restrict      __restrict  // 'restrict' and '__inline__' aren't available
#  define __restrict__  __restrict  // but '__restrict' is.
#elif __cplusplus                   // In language C++ (but not Visual C++),
#  define restrict      __restrict  // 'restrict' isn't available but '__restrict' is.
#elif !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
#  if defined(__GNUC__)             // In gcc,
#    define restrict    __restrict  // 'restrict' isn't available but '__restrict' is.
#  else
#    define restrict                // If 'restrict' isn't available, remove 'restrict'
#    define __restrict              // as well as '__restrict'
#    define __restrict__            // and '__restrict__'.
#  endif
#endif
#ifndef __GNUC__
#  define __attribute__(attr)  // If '__attribute__' isn't available, remove '__attribute__'.
#endif

#ifdef __GNUC__
#  define __DO__          (
#  define __WHILE_ZERO__  )
#else
#  define __DO__          do
#  define __WHILE_ZERO__  while (0)
#endif

#define SWAP(type, a, b)         \
__DO__ {                         \
  type __tmp_swap_var__ = *(a);  \
  *(a) = *(b);                   \
  *(b) = __tmp_swap_var__;       \
} __WHILE_ZERO__


typedef unsigned int uint;
/*!
 * @brief exchange characters in argument string
 * @param [out] str  target string
 * @param [in]  i    index of target string
 * @param [in]  j    index of target string
 * @return Success : 1, Error : 0
 */
__attribute__((const)) inline static int exchange(char *restrict str, uint i, uint j) {
  uint limit = strlen(str) - 1;
  if (i > limit || j > limit) {
    return 0;  // Error!
  }
  SWAP(char, &str[i], &str[j]);
  return 1;    // Success!!
}


/*!
 * @brief print reversed string
 * @param [in] str  target string
 */
inline static void reverse_print(const char *restrict str) {
  int idx = strlen(str) - 1;
  for (; idx >= 0; idx--) {
    putchar(str[idx]);
  }
  putchar('\n');
}
