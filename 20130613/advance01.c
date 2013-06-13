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
 * @brief Advance01
 * @author  koturn 0;
 * @file    advance01.c
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
 
#define CALLOC(type, n)   ((type *)calloc((n), sizeof(type)))  // A Wrapper macro of calloc
#define FREE(ptr_p)       (free(*(ptr_p)), *(ptr_p) = NULL)    // A wrapper macro of free

typedef unsigned int uint;
inline static int  **alloc_2d_array(uint row, uint col);
inline static void free_2d_array(int **array, uint row);
static void show_2d_array(int *const restrict *const restrict array, uint row, uint col);
static void transpose(int *restrict *restrict dst, int *const restrict *const restrict src, uint row, uint col);


/*!
 * @brief An entry point of this program
 * @return exit-status
 */
int main(void) {
  uint row, col;
  uint i;
  int **array, **t_array;
  printf("Number of row = ?\b"); scanf("%u", &row);
  printf("Number of COL = ?\b"); scanf("%u", &col);

  array   = alloc_2d_array(row, col);
  t_array = alloc_2d_array(col, row);
  if (array == NULL || t_array == NULL) {
    fputs("Memory allocation error!\n", stdout);
    return EXIT_FAILURE;
  }

  for (i = 0; i < row; i++) {
    uint j;
    for (j = 0; j < col; j++) {
      int tmp;
      scanf("%d", &tmp);
      array[i][j] = tmp;
    }
  }
  puts("");
  puts("Matrix = ");
  show_2d_array(array, row, col);
  puts("============================================================");

  transpose(t_array, array, row, col);
  puts("Transposed Matrix = ");
  show_2d_array(t_array, col, row);

  free_2d_array(array, row);
  free_2d_array(t_array, row);
  return EXIT_SUCCESS;
}


/*!
 * @brief Allocation 2-demensional array (matrix)
 * @param [in] row  Row of matrix
 * @param [in] col  Column of matrix
 * @return The address of allocated matrix (ERROR: NULL).
 */
inline static int **alloc_2d_array(uint row, uint col) {
  uint i;
  int **array = CALLOC(int *, row);
  if (array == NULL) return NULL;

  for (i = 0; i < row; i++) {
    array[i] = CALLOC(int, col);
    if (array[i] == NULL) return NULL;
  }
  return array;
}


/*!
 * @brief Free 2-demensional array (matrix)
 * @param [in] array  2-demensional array
 * @param [in] row    Row of matrix
 */
inline static void free_2d_array(int **array, uint row) {
  uint i;
  for (i = 0; i < row; i++) {
    FREE(&array[i]);
  }
  FREE(&array);
}


/*!
 * @brief Free 2-demensional array
 * @param [in] array  2-demensional array (matrix)
 * @param [in] row    Row of matrix
 * @param [in] col    Column of matrix
 */
static void show_2d_array(int *const restrict *const restrict array, uint row, uint col) {
  uint i;
  for (i = 0; i < row; i++) {
    uint j;
    for (j = 0; j < col; j++) {
      printf("%4d ", array[i][j]);
    }
    puts("");
  }
}


/*!
 * @brief Transpose matrix
 * @param [in] dst  A matrix which will be assigned transposed matrix
 * @param [in] src  A source matrix which will be assigned transposed matrix
 * @param [in] row  Row of matrix
 * @param [in] col  Column of matrix
 */
static void transpose(int *restrict *restrict dst, int *restrict const *restrict const src, uint row, uint col) {
  uint i;
  for (i = 0; i < row; i++) {
    uint j;
    for (j = 0; j < col; j++) {
      dst[j][i] = src[i][j];
    }
  }
}
