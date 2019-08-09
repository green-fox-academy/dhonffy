#include <stdio.h>

int* find_minimum(const int*, int);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int length = 7;
    printf("%p %d\n", find_minimum(numbers, length), *find_minimum(numbers, length));
    return 0;
}

int* find_minimum(const int* numbers, int length)
{
    int minimum = 0x7fffffff;
    int* minimum_pointer = &minimum;
    for (int i = 0; i < 7; ++i) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum_pointer;
}