#include <stdio.h>
#include "matrix.h"

int main()
{
    printf("Hello, World!\n");
    Matrix a;
    Matrix b;
    float aa[3][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    matrix_create(&a, aa, 4, 3);
    matrix_print(&a);
    matrix_print(&a);

    //matrix_print(&a);
    //matrix_scalar_multiply(3.0, &a);
    matrix_scalar_multiply(3.0, &a, &b);
    matrix_print(&a);
    matrix_print(&b);
    return 0;
}