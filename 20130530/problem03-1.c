#if 0
############################################################
### If you execute this source file as a shell-script,   ###
### you can compile this source file.                    ###
############################################################
gcc -pipe -O3 -s -Wall -Wextra $0 $@ -o ${0%.*}
if [ $? -ne 0 ]; then
  echo '!!!Compile error!!!'
fi
exit
#endif
/*!
 * @brief Problem03-1
 * @author  koturn 0;
 * @file    problem03-1.c
 * @version 0.1
 */

#ifdef _MSC_VER
#  define _USE_MATH_DEFINES
#endif
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

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

#define MALLOC(type, n)        ((type *)malloc(sizeof(type) * (n)))  //!< wrapper-macro of malloc


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  double *const restrict num_p = MALLOC(double, 1);
  if (num_p == NULL) {
    perror("Memory Alocation");
    return EXIT_FAILURE;
  }
  *num_p = M_PI;
  printf("num_pの値は%fです。\n", *num_p);
  free(num_p);
  return EXIT_SUCCESS;
}
