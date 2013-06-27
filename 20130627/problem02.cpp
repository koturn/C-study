#if 0
############################################################
### If you execute this source file as a shell-script,   ###
### you can compile this source file.                    ###
############################################################
g++ -pipe -O3 -s -Wall -Wextra $0 $@ -o ${0%.*}
if [ $? -ne 0 ]; then
  echo '!!!Compile error!!!'
fi
exit
#endif
/*!
 * @brief Problem02
 * @author  koturn 0;
 * @date    2013 06/27
 * @file    problem02.cpp
 * @version 0.1
 */
#include <cstdlib>
#include <iostream>


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  int n;
  std::cout << "数字を入力してください: ";
  std::cin  >> n;
  std::cout << "10倍すると: " << (n * 10) << std::endl;
  std::cout << "16進数に直すと: " << std::hex << n << std::endl;
  return EXIT_SUCCESS;
}
