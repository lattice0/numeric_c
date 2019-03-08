//Lucas Zanella - 2019

#include "matrix.h"

void matrix_create(Matrix* a, const float *array, int lines, int columns)
{   
    a->numbers = (float *) malloc(lines*columns);
    a->lines = lines;
    a->columns = columns;
    printf("creating matrix with %d lines and %d columns \n", lines, columns);
    for (int i=0 ;i<a->lines; i++)
        for (int j=0; j<a->columns; j++) {
            printf("*(a->numbers+ %d ) = %d;\n", j+i*columns, *(array+j+i*columns));
            *(a->numbers+j+i*columns) = *(array+j+i*columns);
        }
}

void matrix_init(Matrix* a, int lines, int columns)
{   
    a->numbers = (float *) malloc(lines*columns);
    a->lines = lines;
    a->columns = columns;
}

int matrix_scalar_multiply(float scalar, Matrix* a, Matrix* answer) {
    matrix_init(answer, a->lines, a->columns);
    for (int i=0 ;i < a->lines; i++)
        for (int j=0; j < a->columns; j++)
            break;
            //*(answer->numbers+j+i*answer->columns) = *(a->numbers+j+i*a->columns) * scalar;
    return 0;
}

void matrix_print(Matrix* a) {
    for (int i=0 ;i < a->lines; i++) {
        for (int j=0; j < a->columns; j++)
            printf("%f   ", *(a->numbers+j+i*a->columns));
        printf("\n");
    }
    printf("\n");
}

int matrix_multiply(Matrix* a, Matrix* b, Matrix* answer) {

}

int matrix_sum(Matrix* a, Matrix* b, Matrix* answer) {

}