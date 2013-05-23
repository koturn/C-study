#if 0
############################################################
### If you execute this source file as a shell-script,   ###
### you can compile this source file.                    ###
############################################################
gcc -pipe -O3 -s -Wall -Wextra $0 $@ -lm -o ${0%.*}
if [ $? -ne 0 ]; then
  echo '!!!Compile error!!!'
fi
exit
#endif
/*!
 * @brief Problem01
 * @author  koturn 0;
 * @file    problem01.c
 * @version 0.1
 */
#include <math.h>
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
#ifndef __GNUC__
#  define __attribute__(attr)  // If '__attribute__' isn't available, remove '__attribute__'.
#endif

#define LENGTH(array)  (sizeof(array) / sizeof((array)[0]))

typedef unsigned int uint;
#if !defined(__GNUC__) || __STDC_VERSION__ < 199901L
__attribute__((const)) inline static double round(double x);
#endif


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  uint i;
  static const double array[] = {78.5, 65.7, 49.3, 88.9};
  puts("入力値 -> 出力値");

  for (i = 0; i < LENGTH(array); i++) {
    printf("%f -> %d\n", array[i], (int)round(array[i]));
  }
  return EXIT_SUCCESS;
}


#if !defined(__GNUC__) || __STDC_VERSION__ < 199901L
inline static double round(double x) {
  return x > 0.0 ? floor(x + 0.5) : (-1.0 * floor(fabs(x) + 0.5));
}
#endif
