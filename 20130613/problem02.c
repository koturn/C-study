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
#include <string.h>
 
#define LENGTH(array)          (sizeof(array) / sizeof((array)[0]))
#define ARRAY_END(array)       ((array) + LENGTH(array))
 
 
/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  char *location[6] = {
    (char *)"Osaka",
    (char *)"Kyoto",
    (char *)"Hyogo",
    (char *)"Nara",
    (char *)"Wakayama",
    (char *)"Mie",
  };
  char **ptr_p, **end;
  for (ptr_p = location, end = ARRAY_END(location); ptr_p != end; ptr_p++) {
    printf("%-10s length = %u\n", *ptr_p, strlen(*ptr_p));
  }
  return EXIT_SUCCESS;
}
