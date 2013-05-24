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
 * @brief Advance02
 * @author  koturn 0;
 * @file    advance02.c
 * @version 0.1
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX(m, n)  ((m) > (n) ? (m) : (n))

#ifdef __cpluplus
static const unsigned int BUF_SIZE = 256;
#else
#  define BUF_SIZE 256
#endif


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  char nstr1[BUF_SIZE], nstr2[BUF_SIZE];
  while (puts("数字を2つ入力してください(EOFを入力すると終了)。"), fgets(nstr1, sizeof(nstr1), stdin) != NULL && fgets(nstr2, sizeof(nstr2), stdin) != NULL) {
    int a = atoi(nstr1);  // ** omit error-check of atoi **
    int b = atoi(nstr2);  // ** omit error-check of atoi **
    if (a != b) {
      printf("%dと%dのうち、大きいのは、%dです。\n\n", a, b, MAX(a, b));
    } else {
      printf("%dと%dは等しいです。\n\n", a, b);
    }
  }
  return EXIT_SUCCESS;
}
