#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculateLength.h"
int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercise with and without using string.h functions
    char* name;
    printf("What's your name?\n");
    scanf("%s", name);
    printf("%d\n", calculateLength(name));
    printf("%d\n", strlen(name));

    return 0;
}

int calculateLength(char* string)
{
    int length = 0;
    while (string[length] != '\0'){
        ++length;
    }
    return length;
}