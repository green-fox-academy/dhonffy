#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    vector_t* vector;
    init(&vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    printf("The vector is empty: %d \n", empty(vector));
    push_back(&vector, 8);
    print(vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    printf("The vector is empty: %d \n", empty(vector));
    push_back(&vector, 88);
    print(vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    pop_back(&vector);
    print(vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    push_back(&vector, 3);
    push_back(&vector, 108);
    push_back(&vector, 95);
    print(vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    insert(&vector, 0, 5);
    print(vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    insert(&vector, 4, 38);
    print(vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    printf("The vector is empty: %d \n", empty(vector));
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    push_back(&vector, 1985);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    pop_back(&vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    pop_back(&vector);
    printf("length: %d. \n", size(vector));
    printf("capacity: %d. \n", capacity(vector));
    print(vector);
    delete(&vector, 3);
    print(vector);

    free(vector);

    return 0;
}