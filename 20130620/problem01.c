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
 * @brief Problem01
 * @author  koturn 0;
 * @file    problem01.c
 * @version 0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#ifdef __cpluplus
unsigned int BUF_SIZE = 1024;
#else
#  define BUF_SIZE  1024
#endif

#define DELETE_EOL(str)  ((str)[strlen(str) - 1] = '\0')  //< delete eol character.

/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  char in_filename[BUF_SIZE], out_filename[BUF_SIZE];
  char buf[BUF_SIZE];
  FILE *restrict in_fp, *restrict out_fp;

  printf("Input in_filename> ");
  fgets(in_filename, sizeof(in_filename), stdin);
  DELETE_EOL(in_filename);
  if ((in_fp = fopen(in_filename, "r")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  printf("Input out_filename> ");
  fgets(out_filename, sizeof(out_filename), stdin);
  DELETE_EOL(out_filename);
  if ((out_fp = fopen(out_filename, "w")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(buf, sizeof(buf), in_fp) != NULL) {
    fputs(buf, out_fp);
  }

  fclose(in_fp);
  fclose(out_fp);
  return EXIT_SUCCESS;
}
