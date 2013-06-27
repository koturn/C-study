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
 * @brief Problem03
 * @author  koturn 0;
 * @file    problem03.c
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
unsigned int BUF_SIZE = 8192;
#else
#  define BUF_SIZE 8192
#endif

static void copy_file(FILE *out_fp, FILE *in_fp);


/*!
 * @brief An entry point of this program
 * @param [in] argc  Number of command-line arguments
 * @param [in] argv  Command-line arguments
 * @return exit-status
 */
int main(int argc, char *argv[]) {
  FILE *restrict in_fp, *restrict out_fp;
  if (argc != 3) {
    fputs("Arguments must be two!\n"
          "[USAGE]\n"
          "  $ ./problem03 [in-binaryFile] [out-binaryFile]\n",
          stderr
    );
    return EXIT_FAILURE;
  }

  if ((in_fp = fopen(argv[1], "rb")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  if ((out_fp = fopen(argv[2], "wb")) == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  copy_file(out_fp, in_fp);

  fclose(in_fp);
  fclose(out_fp);
  return EXIT_SUCCESS;
}


/*!
 * @brief Copy src-file[in_fp] to dst-file[out_fp].
 * @param [in] out_fp  FILE pointer of Destination file.
 * @param [in] in_fp   FILE pointer of Source file.
 */
static void copy_file(FILE *restrict out_fp, FILE *restrict in_fp) {
  static char buf[BUF_SIZE];
  size_t      n_block;
  while ((n_block = fread(buf, sizeof(buf[0]), sizeof(buf), in_fp)) != 0) {
    fwrite(buf, sizeof(buf[0]), n_block, out_fp);
  }
}
