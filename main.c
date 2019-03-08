#include <stdio.h>
#include "matrix.h"

int main()
{
    printf("Hello, World!\n");
    Matrix a;
    float b[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    matrix_create(&a, b, 3, 3);
    return 0;
}