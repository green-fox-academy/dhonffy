#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    vector_t* vector;
    init(&vector);
    push_back(&vector, 8);
    push_back(&vector, 88);
    push_back(&vector, 3);
    push_back(&vector, 108);
    push_back(&vector, 95);
    print(vector);

    free(vector);

    return 0;
}