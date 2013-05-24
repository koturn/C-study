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

// Macros for inline-directive under various environmets
#ifndef __cplusplus  // In language-C
#  if defined(_MSC_VER)           // In Visual C++,
#    define inline      __inline  // 'inline' and '__inline__' aren't available
#    define __inline__  __inline  // but '__inline' is.
#  elif !defined(__GNUC__) && __STDC_VERSION__ < 199901L
#    define inline                // If 'inline' isn't available, remove 'inline'
#    define __inline              // as well as '__inline'.
#  endif
#endif

typedef unsigned int uint;

inline static void print_time(uint sec);


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static const uint SEC = 3673;
  print_time(SEC);
  return EXIT_SUCCESS;
}


/*!
 * @brief print time:hhmmss converted from second
 * @param [in] sec  second (inclue above 60s)
 */
inline static void print_time(uint sec) {
  static const uint HOUR_BASE   = 3600;
  static const uint MINUTE_BASE = 60;
  uint hour = sec / HOUR_BASE;
  uint rem  = sec % HOUR_BASE;

  uint minute  = rem / MINUTE_BASE;
  uint s       = rem % MINUTE_BASE;
  printf("%u秒 = %u時間%u分%u秒", sec, hour, minute, s);
}
