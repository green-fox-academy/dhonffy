#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareStrings.h"

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.
    char *string_to_compare_1 = "alma";
    char *string_to_compare_2 = "alma";
    int result;
    printf("%d", compare_strings(string_to_compare_1, string_to_compare_2));
    return 0;
}

int compare_strings(char *string_to_compare_1, char *string_to_compare_2)
{
    return !strcmp(string_to_compare_1, string_to_compare_2);
}