#include <stdio.h>
#include "repeat.h"
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating.
// The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

int main()
{
    char test[50] = "Apple ";
    int repeat_number = 13;
    printf("%s", repeat(test, repeat_number));
    return 0;
}