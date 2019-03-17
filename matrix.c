//Lucas Zanella - 2019

#include "matrix.h"


float * matrix_element(Matrix *a, int line, int column) {
    return a->numbers+column+line*a->columns;
}

void _matrix_create(Matrix* a, const float *array, int lines, int columns)
{   
    a->numbers = (float *) malloc(lines*columns*sizeof(*a->numbers));
    a->lines = lines;
    a->columns = columns;
    for (int i=0 ;i<a->lines; i++)
        for (int j=0; j<a->columns; j++)
            *matrix_element(a,i,j) = array[j+i*columns];
}

void matrix_delete(Matrix* a) {
    free(a->numbers);
    a->lines = 0;
    a->columns = 0; 
}

void _matrix_init(Matrix* a, int lines, int columns)
{   
    a->numbers = (float *) malloc(lines*columns*sizeof(float));
    a->lines = lines;
    a->columns = columns;
}


int matrix_scalar_multiply(float scalar, Matrix* a, Matrix* answer) {
    _matrix_init(answer, a->lines, a->columns);
    for (int i=0 ;i < answer->lines; i++)
        for (int j=0; j < answer->columns; j++)
            *matrix_element(answer, i,j) = *matrix_element(a,i,j) * scalar;
    return 0;
}

void matrix_print(Matrix* a) {
    for (int i=0 ;i < a->lines; i++) {
        for (int j=0; j < a->columns; j++)
            printf("%f   ",*matrix_element(a,i,j));
        printf("\n");
    }
    printf("\n");
}

void matrix_wolfram_print(Matrix* a) {
    printf("{");
    for (int i=0 ;i < a->lines; i++) {
        printf("{");
        for (int j=0; j < a->columns; j++)
            if (j!=a->columns-1){
                printf("%.2f, ",*matrix_element(a,i,j));
            } else {
                printf("%.2f ",*matrix_element(a,i,j));
            }
        printf("}");
        if (i!=a->lines-1) {
            printf(",");
            printf("\n");
        }
    }
    printf("}");
    printf("\n");
}

void matrix_latex_print(Matrix* a) {
    printf("\\begin{bmatrix}\n");
    for (int i=0 ;i < a->lines; i++) {
        for (int j=0; j < a->columns; j++) {
            if (j!=a->columns-1) {
                printf("%f & ",*matrix_element(a,i,j));
            } else {
                printf("%f  ",*matrix_element(a,i,j));
                if (i!= a->lines -1)
                    printf("\\\\");
            }
        }
        printf("\n");
    }
    printf("\\end{bmatrix}");
    printf("\n");
}

//Takes the dot product of a line of a by a column of b
float matrix_dot_product(Matrix* a, Matrix* b, int line, int column) {
    float answer = 0;
    for (int k=0; k<b->lines; k++)
        answer += (*matrix_element(a,line,k))*(*matrix_element(b,k,column));
    return answer;
}

int matrix_multiply(Matrix* a, Matrix* b, Matrix* answer) {
    _matrix_init(answer, a->lines, b->columns);
    for (int j=0; j<answer->columns; j++)
        for (int i=0 ;i<answer->lines; i++) {
            *matrix_element(answer,i,j) = matrix_dot_product(a, b, i, j);
        }
    
}

int matrix_have_equal_dimension(Matrix* a, Matrix* b) {
    return a->lines==b->lines && a->columns == b->columns;
}

int matrix_sum(Matrix* a, Matrix* b, Matrix* answer) {
    if (!matrix_have_equal_dimension(a,b)) {
        printf("ERROR: matrices don't have the same size\n");
        matrix_print(a);
        matrix_print(b);
        return -1;
    }
    _matrix_init(answer, a->lines, a->columns);
    for (int i=0 ;i<answer->lines; i++)
            for (int j=0; j<answer->columns; j++)
                *matrix_element(answer,i,j) = *matrix_element(a,i,j) + *matrix_element(b,i,j);
    return 0;
}

int matrix_create_identity(int dimension, Matrix* answer) {
    _matrix_init(answer, dimension, dimension);
    for (int i=0 ;i<dimension; i++)
        *matrix_element(answer,i,i) = 1;
}

int system_create(Matrix* leftMatrix, Matrix* rightMatrix, System * system) {
    system->leftMatrix = leftMatrix;
    system->rightMatrix = rightMatrix;
}

//TODO: return nonzero if something is not right with dimensions
int _system_get_line(System* system, int line, Matrix* leftLine, float* rightElement) {
    Matrix* left = system->leftMatrix;
    Matrix* right = system->rightMatrix;
    _matrix_init(leftLine, 1, leftLine->columns);
    for (int j = 0; j<left->columns; j++) {
        *matrix_element(leftLine, 0, j) = *matrix_element(left, line, j);
    }
    *rightElement = *matrix_element(right, line, 0);
    return 0;
}

void system_print_line(System* system, int line) {
    Matrix* leftLine;
    float * rightElement;
    _system_get_line(system, line, leftLine, rightElement);
    matrix_print(leftLine);
    printf(" = ");
    printf(rightElement);
}

//line a = c_1 * line a + c_2 * line b
void system_sum_line(System * system, int c_1, int a, int c_2, int b) {

}