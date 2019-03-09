#include <stdio.h>
#include "matrix.h"

int main()
{
    printf("Hello, World!\n");
    Matrix a;
    Matrix b;
    Matrix c;
    Matrix d;
    Matrix e;
    float aa[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    matrix_create(&a, aa, 3, 3);
    matrix_print(&a);
    matrix_scalar_multiply(3, &a, &b);
    matrix_print(&b);
    matrix_sum(&a,&b,&c);
    matrix_print(&c);
    matrix_create_identity(5,&d);
    matrix_print(&d);
    matrix_multiply(&a,&b,&e);
    matrix_print(&e);

    matrix_wolfram_print(&a);
    matrix_wolfram_print(&b);

    return 0;
}