#include <stdio.h>
#include "matrix.h"
int main()
{
    Matrix a;
    float aa[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    MATRIX_BEGIN(a, aa);
    /*
    Matrix b;
    Matrix c;
    Matrix d;
    Matrix e;

    matrix_print(&a);
    matrix_scalar_multiply(3, &a, &b);
    matrix_print(&b);
    matrix_sum(&a,&b,&c);
    matrix_print(&c);
    _matrix_create_identity(5,&d);
    matrix_print(&d);
    matrix_multiply(&a,&b,&e);
    matrix_print(&e);
    matrix_wolfram_print(&a);
    matrix_wolfram_print(&b);

    Matrix f;
    Matrix g;
    Matrix h;
    float ff[2][3] = {{1,2,3},{4,5,6}};
    float gg[3][1] = {{1},{2},{3}};
    MATRIX_BEGIN(f, ff);
    MATRIX_BEGIN(g, gg);
    matrix_multiply(&f,&g,&h);
    matrix_print(&h);
    matrix_wolfram_print(&f);
    matrix_wolfram_print(&g);
    */
    matrix_latex_print(&a);

    

    return 0;
}