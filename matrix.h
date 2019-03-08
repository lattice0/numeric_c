//Lucas Zanella - 2019

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
  

typedef struct Matrix {
    int lines; //number of lines
    int columns; //number of columns
    float* numbers; //elements of our matrix
} Matrix;

