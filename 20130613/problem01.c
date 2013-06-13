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
 * @brief Problem01.c
 * @author  koturn 0;
 * @file    problem01.c
 * @version 0.1
 */
#include <stdio.h>
#include <stdlib.h>
 
 
/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  int num  = 100;
  int *p   = &num;
  int **pp = &p;
  printf("pp  = 0x%p (address)\n", pp);
  printf("p   = 0x%p (address)\n", p);
  printf("num = %d (value)\n", num);
  return EXIT_SUCCESS;
}
