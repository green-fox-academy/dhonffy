#include <stdio.h>
#include "concat_string.h"
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

int main()
{
    char begin[500] = "";
    char end[50] = "asd";

    concat_string(begin, end);
    return 0;
}