#include <stdio.h>
#include "matrix.h"

int main()
{
    Matrix a;
    float aa[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    MATRIX_BEGIN(a, aa);
    Matrix b;
    float bb[3] = {10,11,12};
    VECTOR_BEGIN(b, bb);
    System s1;
    system_create(&a,&b,&s1);
    system_print(&s1);
    //system_sum_line(System * system, int c_1, int a, int c_2, int b); line a = c_1 line a + c_2 line b
    system_sum_line(&s1, 2, 0, 3, 1);
    system_print(&s1);
    //system_print_line(&s1, 0);
    //_matrix_wolfram_print(&a);
    //printf(_matrix_wolfram_print(&a));
    //matrix_print(s1.rightMatrix);
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
    matrix_create_identity(5,&d);
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
    //matrix_latex_print(&a);

    

    return 0;
}