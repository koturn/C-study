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
#include "problem03.h"


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static char str[] = "thsoiasoneu";
  printf("元の文字列:%s\n", str);

  if (!exchange(str, 0, 4)) {
    fputs("エラーが発生しました\n", stderr);
    return EXIT_FAILURE;
  }
  printf("1番目と5番目を入れ替えた文字列:%s\n", str);
  printf("さらに逆順に表示した文字列:");
  reverse_print(str);
  return EXIT_SUCCESS;
}
