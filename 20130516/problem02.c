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
inline static void print_time(uint min, uint sec);


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  static const uint MIN = 60;
  static const uint SEC = 3600;
  print_time(MIN, SEC);
  return EXIT_SUCCESS;
}


/*!
 * @brief print hour converted from 'mmss'
 * @param [in] min  minute
 * @param [in] sec  second
 */
inline static void print_time(uint min, uint sec) {
  static const uint SEC_RATE    = 3600;
  static const uint MINUTE_RATE = 60;
  uint sum_sec = min * MINUTE_RATE + sec;
  double hour = (double)sum_sec / SEC_RATE;

  printf("%u分%u秒 = %f時間\n", min, sec, hour);
}
