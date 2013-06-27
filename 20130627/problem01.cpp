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
 * @brief Problem01
 * @author  koturn 0;
 * @date    2013 06/27
 * @file    problem01.cpp
 * @version 0.1
 */
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  std::string buf;
  std::cout << "10文字以内で文字を入力してください: ";
  std::cin  >> std::setw(10) >> buf;
  std::cout << buf << std::endl;
  return EXIT_SUCCESS;
}
