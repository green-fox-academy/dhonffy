#include <stdio.h>

int main()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    char* name = "Bob";

    printf("Pointer a: %d\n", &a);
    printf("a: %d\n", a);
    printf("Pointer b: %d\n", &b);
    printf("b: %.1f\n", b);
    printf("Pointer name: %d\n", &name);
    printf("name: %s\n", name);

    return 0;
}