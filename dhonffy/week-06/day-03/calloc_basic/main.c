#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous exercise? the end of the array is filled with zeros

int main()
{
    int* array = calloc(10, sizeof(int));
    for (int i = 0; i < 5; ++i) {
        array[i] = i;
    }
    for (int j = 0; j < 10; ++j) {
        printf("%d\n", array[j]);
    }

    free(array);

    return 0;
}