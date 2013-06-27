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
 * @brief Problem03
 * @author  koturn 0;
 * @date    2013 06/27
 * @file    problem03.cpp
 * @version 0.1
 */
#include <cstdlib>
#include <iostream>
#include <string>


class Man {
  private:
    std::string name;
    int         height;
    int         weight;
    int         age;
  public:
    Man(std::string const &name, int height, int weight, int age);
    std::string getName(void)   const { return name; }
    int         getHeight(void) const { return height; }
    int         getWeight(void) const { return weight; }
    int         getAge(void)    const { return age; }

    void        setName(std::string const &name) { this->name   = name; }
    void        setHeight(int height)            { this->height = height; }
    void        setWeight(int weight)            { this->weight = weight; }
    void        setAge(int age)                  { this->age    = age; }
};


Man::Man(std::string const &name, int height, int weight, int age) {
  this->name   = name;
  this->height = height;
  this->weight = weight;
  this->age    = age;
}


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  std::string name;
  int         height;
  int         weight;
  int         age;

  std::cout << "名前を入力してください: ";
  std::cin  >> name;
  std::cout << "身長を入力してください: ";
  std::cin  >> height;
  std::cout << "体重を入力してください: ";
  std::cin  >> weight;
  std::cout << "年齢を入力してください: ";
  std::cin  >> age;

  Man man(name, height, weight, age);
  std::cout << "「どうも" << man.getName()   << "です．\n"
            << "身長は"   << man.getHeight() << "cm, "
            << "体重: "   << man.getWeight() << "kg, "
            << "年齢: "   << man.getAge()    << "歳です．\n"
            << "よろしくおねがいします．」"
            << std::endl;
  return EXIT_SUCCESS;
}
