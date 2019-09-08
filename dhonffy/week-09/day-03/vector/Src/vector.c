#include "vector.h"
#include <cmsis_os.h>
#include <stdlib.h>
#include <stdio.h>

void vector_init(vector_t** vector)
{
    vector_t* vector_value = *vector;
    vector = NULL;
    vector_value->length = 0;
    vector_value->capacity = 1;
    vector_value->begin = (int *) pvPortMalloc(sizeof(int));
    vector = &vector_value;
}

void vector_push_back(vector_t **vector, int data)
{
    vector_t* vector_value = *vector;
    if (vector_value->capacity <= vector_value->length){
        vector_value->capacity += 5;
        pvPortRealloc(vector_value->begin, vector_value->capacity * sizeof(data));
    }
    vector_value->begin[vector_value->length] = data;
    ++vector_value->length;
    vector = &vector_value;
}

void vector_pop_back(vector_t **vector)
{
    vector_t* vector_value = *vector;
    if (vector_value->capacity >= vector_value->length + 10){
        vector_value->capacity -= 10;
        pvPortRealloc(vector_value->begin, vector_value->capacity * sizeof(int));
    }
    --vector_value->length;
    vector = &vector_value;
}

void vector_insert(vector_t** vector, int index, int data)
{
    vector_t* vector_value = *vector;
    if (vector_value->capacity <= vector_value->length){
        vector_value->capacity += 5;
        pvPortRealloc(vector_value->begin, vector_value->capacity * sizeof(data));
    }
    for (int i = 0; i < vector_value->length - index; ++i) {
        vector_value->begin[vector_value->length - i] = vector_value->begin[vector_value->length - i - 1];
    }
    vector_value->begin[index + 1] = data;
    ++vector_value->length;
    vector = &vector_value;
}

int vector_delete(vector_t** vector, int index)
{
    vector_t* vector_value = *vector;
    if(index >= vector_value->length){
        return 0;
    }
    for (int i = index; i < vector_value->length; ++i) {
        vector_value->begin[i] = vector_value->begin[i + 1];
    }
    if (vector_value->capacity >= vector_value->length + 10){
        vector_value->capacity -= 10;
        pvPortRealloc(vector_value->begin, vector_value->capacity * sizeof(int));
    }
    --vector_value->length;
    vector = &vector_value;
    return 1;
}

int vector_size(vector_t* vector)
{
    return  vector->length;
}

int vector_capacity(vector_t* vector)
{
    return  vector->capacity;
}

int vector_empty(vector_t* vector)
{
    if(vector->length == 0){
        return 1;
    } else {
        return 0;
    }
}

void vector_print(vector_t* vector)
{
    for (int i = 0; i < vector->length; ++i) {
        printf("%d. %d\n", i + 1, vector->begin[i]);
    }
}

int vector_search(vector_t* vector, int data)
{
    for (int i = 0; i < vector->length; ++i) {
        if (vector->begin[i] == data){
            return i;
        }
    }
    return -1;
}

int vector_get(vector_t* vector, int index)
{
    return vector->begin[index];
}
