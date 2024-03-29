#include <iostream>

void swap(int *a, int *b);

int main()
{
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void function and pointers

    int a = 10;
    int b = 316;
    int *aPtr = &a;
    int *bPtr = &b;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}