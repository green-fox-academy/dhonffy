#include <stdio.h>
#include <stdlib.h>


// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free

int main()
{
    int* array = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        array[i] = (i + 1) * 2;
    }
    realloc(array, 0 * sizeof(int));
    free(array);

    return 0;
}