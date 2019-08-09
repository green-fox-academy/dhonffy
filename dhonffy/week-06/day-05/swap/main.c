#include <stdio.h>

void swap(int*, int*);

int main ()
{
    // Create a function which swaps the values of 'a' and 'b' variables.
    // This time use a void function and pointers.

    int a = 10;
    int b = 316;
    swap(&a, &b);
    printf("a = %d\nb = %d", a ,b);
    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}