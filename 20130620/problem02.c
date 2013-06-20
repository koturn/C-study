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

#ifdef __cpluplus
unsigned int BUF_SIZE = 1024;
#else
#  define BUF_SIZE  1024
#endif
static const char *const restrict OUT_FILENAME = "out.txt";


/*!
 * @brief An entry point of this program
 * @param [in] argc  Number of command-line arguments
 * @param [in] argv  Command-line arguments
 * @return exit-status
 */
int main(int argc, char *argv[]) {
  char buf[BUF_SIZE];
  FILE *restrict in_fp, *restrict out_fp;

  if (argc != 2) {
    fputs("Arguments must be one!\n", stderr);
    return EXIT_FAILURE;
  }

  if ((in_fp = fopen(argv[1], "r")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  if ((out_fp = fopen(OUT_FILENAME, "w")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(buf, sizeof(buf), in_fp) != NULL) {
    printf("%s", buf);
    fputs(buf, out_fp);
  }

  fclose(in_fp);
  fclose(out_fp);
  return EXIT_SUCCESS;
}
