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
#include <string.h>

typedef unsigned int uint;
#define LENGTH(array)    (sizeof(array) / sizeof((array)[0]))
#define DELETE_EOL(str)  ((str)[strlen(str) - 1] = '\0')  //< delete eol character.

#ifdef __cplusplus
static const uint N = 3;
static const uint BUF_SIZE = 256;
#else
#  define N        3
#  define BUF_SIZE 256
#endif


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static char strs[N][BUF_SIZE];
  static char nstr[BUF_SIZE];
  uint i, n;

  for (i = 0; i < N; i++) {
    printf("%uつ目の文字列を入力してください：", i + 1);
    fgets(strs[i], LENGTH(strs[i]), stdin);
  }

  printf("何個の文字列を表示しますか？：");
  fgets(nstr, sizeof(nstr), stdin);
  n = atoi(nstr);  // ** omit error check of atoi. **
  n = n < N ? n : N;
  for (i = 0; i < n; i++) {
    DELETE_EOL(strs[i]);
    printf("「%s」\n", strs[i]);
  }
  return EXIT_SUCCESS;
}
