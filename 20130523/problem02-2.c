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
 * @brief Problem02-2
 * @author  koturn 0;
 * @file    problem02-2.c
 * @version 0.1
 */
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

#define ISIN(x, a, b)  ((a) <= (x) && (x) <= (b))
#define DEQ(x, y)      ISIN((x), (y) - EPS, (y) + EPS)
static const double EPS = 10e-9;

typedef unsigned int uint;
__attribute__((const)) inline static double convert(double x);


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static const double x = 7.9;
  double y = x;
  uint cnt = 0;

  double prev_y = 0.0;
  while (!DEQ(y, prev_y)) {
    cnt++;
    prev_y = y;
    y = convert(y);
  }
  printf("%fに関数を%u回用いると%fになります\n", x, cnt, y);
  return EXIT_SUCCESS;
}


/*!
 * @brief convert number as written in handout
 * @param [in] x  a number
 * @return converted x
 */
inline static double convert(double x) {
  return x < 100 ? x * 3
                 : x >= 150 ? x / 2
                            : x;
}
