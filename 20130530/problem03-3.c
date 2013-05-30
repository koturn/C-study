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
 * @brief Problem03-3
 * @author  koturn 0;
 * @file    problem03-3.c
 * @version 0.1
 */
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

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
static const uint ARRAY_SIZE = 10;
#else
#  define ARRAY_SIZE 10
#endif

#define CALLOC(type, n)  ((type *)calloc((n), sizeof(type)))  //!< wrapper-macro of calloc


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  uint i;
  int *const restrict num = CALLOC(int, ARRAY_SIZE);
  if (num == NULL) {
    perror("Memory Alocation");
    return EXIT_FAILURE;
  }

  for (i = 0; i < (ARRAY_SIZE >> 1); i++) {
    num[i] = i;
  }
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("num[%u] = %d\n", i, num[i]);
  }

  free(num);
  return EXIT_SUCCESS;
}
