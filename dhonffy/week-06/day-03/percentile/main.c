#include <stdio.h>
#include <stdlib.h>
#include "read_size.h"
#include "ask_value.h"
#include "copy_matrix_to_array.h"
#include "calculate_percentile.h"
//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int main()
{
    int matrix_size = read_size();
    int line_size = read_size();
    int** matrix = malloc(matrix_size * sizeof(int*));
    for (int i = 0; i < matrix_size; ++i) {
        int* line = malloc(line_size * sizeof(int));
        for (int j = 0; j < line_size; ++j) {
            line[j] = ask_value(i, j);
        }
        matrix[i] = line;
    }

    int* ordered_array = malloc(matrix_size * line_size * sizeof(int));
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < line_size; ++j) {
            printf("%d ", matrix[i][j]);
            ordered_array[i * line_size + j] = matrix[i][j];
        }
        printf("\n");
    }

    for (int i = 0; i < matrix_size; ++i) {
        free(&matrix[i]);
    }
    free(matrix);

    int swap;
    for (int i = 0 ; i < matrix_size * line_size - 1; i++)
    {
        for (int j = 0 ; j < matrix_size * line_size - i - 1; j++)
        {
            if (ordered_array[j] > ordered_array[j + 1])
            {
                swap       = ordered_array[j];
                ordered_array[j]   = ordered_array[j + 1];
                ordered_array[j + 1] = swap;
            }
        }
    }




    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < line_size; ++j) {
            printf("%d ", ordered_array[i * line_size + j]);
        }
        printf("\n");
    }

    //    printf("The 90th percentile is: %d.", calculate_percentile(*ordered_array, matrix_size * line_size, 90));
    int percentile = 90;
    int element = (int)((float)matrix_size * line_size / 100.0 * (float)percentile) - 1;
    printf("The 90th percentile is: %d.\n", ordered_array[element]);

    percentile = 80;
    element = (int)((float)matrix_size * line_size / 100.0 * (float)percentile) - 1;
    printf("The 80th percentile is: %d.\n", ordered_array[element]);

    free(ordered_array);
    return 0;
}
