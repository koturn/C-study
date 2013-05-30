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
 * @brief Problem01-2
 * @author  koturn 0;
 * @file    problem01-2.c
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
// Macros for restrict-qualifier under various environmets
#if _MSC_VER >= 1400                // In Visual C++ (after Visual C++ 2005),
#  define restrict      __restrict  // 'restrict' and '__inline__' aren't available
#  define __restrict__  __restrict  // but '__restrict' is.
#elif __cplusplus                   // In language C++ (but not Visual C++),
#  define restrict      __restrict  // 'restrict' isn't available but '__restrict' is.
#elif !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
#  if defined(__GNUC__)             // In gcc,
#    define restrict    __restrict  // 'restrict' isn't available but '__restrict' is.
#  else
#    define restrict                // If 'restrict' isn't available, remove 'restrict'
#    define __restrict              // as well as '__restrict'
#    define __restrict__            // and '__restrict__'.
#  endif
#endif


typedef struct {
  char *name;
  int   grade;
  int   class;
  int   point;
} Student;

inline static void show_Student_data(const Student *restrict student);

/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  Student student = {"Ueta Koji", 4, 2, 80};
  show_Student_data(&student);
  return EXIT_SUCCESS;
}


/*!
 * @brief Show values of member of struct:Student
 * @param [in] student  struct:Student which you want to show values of member of
 */
inline static void show_Student_data(const Student *restrict student) {
  printf(
      "名前：%s\n"
      "学年：%d\n"
      "クラス：%d\n"
      "得点：%d\n",
      student->name, student->grade, student->class, student->point
  );
}
