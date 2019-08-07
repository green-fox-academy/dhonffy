#include "repeat.h"
#include <stdlib.h>

char* repeat(char* orig, int repetation)
{
    int orig_length = 0;
    while (orig[orig_length] != 0) {
        ++orig_length;
    }
    char* repeated = malloc(repetation * orig_length * sizeof(char));
    for (int i = 0; i < repetation; ++i) {
        for (int j = 0; j < orig_length; ++j) {
            repeated[i * orig_length + j] = orig[j];
        }
    }
    repeated[repetation * orig_length] = '\0';
    return repeated;
}