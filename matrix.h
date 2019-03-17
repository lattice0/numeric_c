//Lucas Zanella - 2019
#include <stdio.h>
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))
#define MATRIX_BEGIN(x, xx) matrix_create(&x, xx, LEN(xx), LEN(xx[0]))

typedef struct Matrix {
    int lines; //number of lines
    int columns; //number of columns
    float* numbers; //elements of our matrix
} Matrix;

float * matrix_element(Matrix *a, int line, int column);
void    matrix_create(Matrix* a, const float *array, int lines, int columns);
void    matrix_init(Matrix* a, int lines, int columns);
int     matrix_scalar_multiply(float scalar, Matrix* a, Matrix* answer);
void    matrix_print(Matrix* a);
int     matrix_multiply(Matrix* a, Matrix* b, Matrix* answer);
int     matrix_sum(Matrix* a, Matrix* b, Matrix* answer);
int     matrix_create_identity(int dimension, Matrix* answer);
void    matrix_wolfram_print(Matrix* a);
void    matrix_latex_print(Matrix* a);
void    matrix_delete(Matrix* a);