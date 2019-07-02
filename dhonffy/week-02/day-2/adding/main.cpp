#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;
    int *aPtr = &a;
    int *bPtr = &b;

    int result;
    result = *aPtr + *bPtr;

    return 0;
}