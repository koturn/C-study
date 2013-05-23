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
 * @brief Problem02-1
 * @author  koturn 0;
 * @file    problem02-1.c
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

#define CHAR_TO_NUM(c)  ((c) - '0')

__attribute__((const)) inline static int binary2decimal(const char *restrict bstr);


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static const int   num  = 124;
  static const char *bstr = "1110";
  printf("%d + 0b%s = %d\n", num, bstr, num + binary2decimal(bstr));
  return EXIT_SUCCESS;
}


/*!
 * @brief convert binary string to decimal value
 * @param [in] bstr  binary string
 * @return bstr value in decimal.
 */
inline static int binary2decimal(const char *restrict bstr) {
  int sum = 0;
  for (; *bstr != '\0'; bstr++) {
    sum <<= 1;
    sum += CHAR_TO_NUM(*bstr);
  }
  return sum;
}
