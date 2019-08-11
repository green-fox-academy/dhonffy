#include <stdio.h>
#include <stdlib.h>

int find_value(int*, int, int);

int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1
    int length = 5;
    int* searched_array = malloc(length * sizeof(int));
    for (int i = 0; i < length; ++i) {
        searched_array[i] = 10 * (i + 1);
    }
    int index = find_value(searched_array, length, 20);
    printf("%d", index);
    free(searched_array);
    return 0;
}

int find_value(int* searched_array, int length, int what_to_find)
{
    for (int i = 0; i < length; ++i) {
        if (searched_array[i] == what_to_find){
            return i;
        }
    }
    return -1;
}
