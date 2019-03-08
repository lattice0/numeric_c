#include <stdio.h>
#include "matrix.h"

int main()
{
    printf("Hello, World!\n");
    Matrix a;
    Matrix b;
    float aa[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    matrix_create(&a, aa, 3, 3);
    matrix_scalar_multiply(3, &a, &b);
    matrix_print(&a);
    return 0;
}