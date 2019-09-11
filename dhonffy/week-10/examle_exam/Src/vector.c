#include "vector.h"

void vector_init(vector_t** head)
{
    vector_t* vector = *head;
    vector = NULL;
    vector->length = 0;
    vector->capacity = 0;
}

