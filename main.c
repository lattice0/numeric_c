#include <stdio.h>
#include "matrix.h"

int main()
{
    printf("Hello, World!\n");
    Matrix a;
    Matrix b;
    Matrix c;
    Matrix d;
    float aa[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    matrix_create(&a, aa, 4, 3);
    matrix_print(&a);
    matrix_scalar_multiply(3, &a, &b);
    matrix_print(&b);
    matrix_sum(&a,&b,&c);
    matrix_print(&c);
    matrix_create_identity(5,&d);
    matrix_print(&d);
    return 0;
}