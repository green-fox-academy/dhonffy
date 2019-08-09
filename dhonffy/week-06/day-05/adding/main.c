#include <stdio.h>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;
    int* pointer_a = &a;
    int* pointer_b = &b;
    int c;
    int* pointer_c = &c;
    *pointer_c = *pointer_a + *pointer_b;
    printf("%d\n", c);
    return 0;
}