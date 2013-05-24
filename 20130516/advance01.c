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
 * @brief Advance01
 * @author  koturn 0;
 * @file    advance01.c
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
  static char nstr[BUF_SIZE];
  int n;
  printf("数字を入力してください：");
  fgets(nstr, sizeof(nstr), stdin);
  n = atoi(nstr);  // ** omit error-check of atoi. **

  /*** !!! Another answer !!!
  n % 15 == 0 ? printf("%dは3の倍数であり、5の倍数です。\n", n)
              : n % 5 == 0 ? printf("%dは5の倍数です。\n", n)
                           : n % 3 == 0 ? printf("%dは3の倍数です。\n", n)
                                        : printf("%dは3の倍数でも、5の倍数でもありません。\n", n);
   ***/
  if (n % 15 == 0) {
    printf("%dは3の倍数であり、5の倍数です。\n", n);
  } else if (n % 5 == 0) {
    printf("%dは5の倍数です。\n", n);
  } else if (n % 3 == 0) {
    printf("%dは3の倍数です。\n", n);
  } else {
    printf("%dは3の倍数でも、5の倍数でもありません。\n", n);
  }
  return EXIT_SUCCESS;
}
