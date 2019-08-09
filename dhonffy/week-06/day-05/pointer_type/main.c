#include <stdio.h>

int main()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    char* name = "Bob";
    int* pointer_a = &a;
    double* pointer_b = &b;
    char* pointer_name = name;

    printf("Pointer a: %p\n", pointer_a);
    printf("a: %d\n", *pointer_a);
    printf("Pointer b: %p\n", pointer_b);
    printf("b: %.1f\n", *pointer_b);
    printf("Pointer name: %p\n", pointer_name);
    printf("name: %s\n", pointer_name);

    return 0;
}