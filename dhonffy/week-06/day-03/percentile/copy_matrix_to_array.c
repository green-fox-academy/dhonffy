#include "copy_matrix_to_array.h"
#include <stdlib.h>
#include <stdio.h>
int* copy_matrix_to_array(int** matrix)
{
    int line_size = sizeof(matrix[0]);
    int matrix_size = sizeof(matrix /*/ matrix[0]*/);
    int* ordered_array = malloc(matrix_size * line_size * sizeof(int));
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < line_size; ++j) {
            printf("%d ", matrix[i][j]);
            ordered_array[i * line_size + j] = matrix[i][j];
        }
        printf("\n");
    }
    return ordered_array;
}