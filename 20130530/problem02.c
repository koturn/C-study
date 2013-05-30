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
 * @brief Problem02
 * @author  koturn 0;
 * @file    problem02.c
 * @version 0.1
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
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


typedef unsigned int uint;
#ifdef __cplusplus
static const uint N        = 5;
static const uint BUF_SIZE = 1024;
#else
#  define N         5
#  define BUF_SIZE  1024;
#endif

#define DELETE_EOL(str)  ((str)[strlen(str) - 1] = '\0')  //!< delete eol character.
inline static int str2int(const char *restrict nstr);
static void reverse_copy(int *restrict dst, const int *restrict src, uint n);


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static int  a[N];
  static int  b[N];
  static char buf[N];
  uint i;
  for (i = 0; i < N; i++) {
    int n;
    printf("整数を入力してください：a[%u] = ?\b", i);
    fgets(buf, sizeof(buf), stdin);
    DELETE_EOL(buf);
    n = str2int(buf);
    a[i] = n;
  }
  reverse_copy(b, a, N);
  for (i = 0; i < N; i++) {
    printf("b[%u] = %d\n", i, b[i]);
  }
  return EXIT_SUCCESS;
}


/*!
 * @brief convert string to integer
 * @param [in] nstr  target string
 * @return value of str
 */
inline static int str2int(const char *restrict nstr) {
  char *check;
  int   num = strtol(nstr, &check, 10);  // char * -> long
  if (*check != '\0') {
    fputs("文字列に数値以外がありました\n", stderr);
    exit(EXIT_FAILURE);
  }
  if (num == INT_MAX) {
    fputs("値が大きすぎます\n", stderr);
    exit(EXIT_FAILURE);
  }
  return num;
}


/*!
 * @brief copy array with reverse-order
 * @param [out] dst  destination=integer array
 * @param [in]  src  source-integer array
 * @param [in]  n    number of elements to copy
 */
static void reverse_copy(int *restrict dst, const int *restrict src, uint n) {
  uint i;
  for (i = 0; i < n; i++) {
    dst[i] = src[n - i - 1];
  }
}
