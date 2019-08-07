#include "concat_string.h"
#include <stdlib.h>
#include <stdio.h>
char* concat_string(char* begin, char* end)
{
    int begin_length = 0;
    while (begin[begin_length] != 0) {
        ++begin_length;
    }
    int end_length = 0;
    while (end[end_length] != 0) {
        ++end_length;
    }
    char *concat = malloc((begin_length + end_length + 1) * sizeof(char));
    for (int i = 0; i < begin_length; ++i) {
        concat[i] = begin[i];
    }
    for (int i = 0; i < end_length; ++i) {
        concat[begin_length + i] = end[i];
    }
    concat[begin_length + end_length] = '\0';
    printf("%s", concat);
    return concat;
}