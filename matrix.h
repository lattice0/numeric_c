//Lucas Zanella - 2019
#include <stdio.h>
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))
#define MATRIX_BEGIN(x, xx) _matrix_create(&x, xx, LEN(xx), LEN(xx[0]))

typedef struct Matrix {
    int lines; //number of lines
    int columns; //number of columns
    float* numbers; //elements of our matrix
} Matrix;

typedef struct System {
    Matrix* leftMatrix;//Left matrix of the system
    Matrix* rightMatrix;//Right matrix of the system (a vector)
} System;

float * matrix_element(Matrix *a, int line, int column);
int     matrix_scalar_multiply(float scalar, Matrix* a, Matrix* answer);
void    matrix_print(Matrix* a);
int     matrix_multiply(Matrix* a, Matrix* b, Matrix* answer);
int     matrix_sum(Matrix* a, Matrix* b, Matrix* answer);
int     matrix_create_identity(int dimension, Matrix* answer);
void    matrix_wolfram_print(Matrix* a);
void    matrix_latex_print(Matrix* a);
void    matrix_delete(Matrix* a);
int     system_create(Matrix* leftMatrix, Matrix* rightMatrix, System * system);
void    system_print_line(System* system, int line)