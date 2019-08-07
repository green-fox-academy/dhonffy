#include <stdio.h>
#include <stdlib.h>
#include "read_size.h"
#include "ask_value.h"
//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int main()
{
    int x = read_size();
    int y = read_size();
    int* line = malloc(y * sizeof(int));
    int* matrix = malloc(x * sizeof(line));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            ask_value(i, j);
        }
    }
    
    return 0;
}