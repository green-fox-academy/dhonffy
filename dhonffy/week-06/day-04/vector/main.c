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
    printf("length: %d. \n", size(vector));
    insert(&vector, 0, 5);
    print(vector);
    printf("length: %d. \n", size(vector));
    insert(&vector, 4, 38);
    print(vector);
    printf("length: %d. \n", size(vector));

    free(vector);

    return 0;
}