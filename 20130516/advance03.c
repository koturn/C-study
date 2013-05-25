#if 0
############################################################
### If you execute this source file as a shell-script,   ###
### you can compile this source file.                    ###
############################################################
gcc -pipe -O3 -s -Wall -Wextra -fopenmp $0 $@ -o ${0%.*}
if [ $? -ne 0 ]; then
  echo '!!!Compile error!!!'
fi
exit
#endif
/*!
 * @brief Advance03
 * @author  koturn 0;
 * @file    advance03.c
 * @version 0.1
 */
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
static const unsigned int BUF_SIZE = 256;
#else
#  define BUF_SIZE 256
#endif


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static char nstrs[BUF_SIZE];
  int n;
  int i;

  printf("数字を入力してください。：");
  fgets(nstrs, sizeof(nstrs), stdin);
  n = atoi(nstrs);

  #pragma omp parallel for
  for (i = 0; i < n; i++) {
    puts("**********");
  }
  return EXIT_SUCCESS;
}
