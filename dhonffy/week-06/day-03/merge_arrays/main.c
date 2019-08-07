#include <stdio.h>
#include <stdlib.h>


// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free

int main()
{
    int* even = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        even[i] = (i + 1) * 2;
    }
    int* odd = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        odd[i] = i * 2 + 1;
    }
    for (int i = 0; i < 10; ++i) {
        even[i] = odd[i];
    }
    for (int j = 0; j < 10; ++j) {
        printf("%d\n", even[9 - j]);
    }
    free(even);
    free(odd);

    return 0;
}