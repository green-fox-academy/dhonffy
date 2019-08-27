#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void init(vector_t** vector)
{
    vector_t* vector_value = *vector;
    vector = NULL;
    vector_value->length = 0;
    vector_value->capacity = 1;
    vector_value->begin = (int *) malloc(sizeof(int));
    vector = &vector_value;
}

void push_back(vector_t **vector, int data)
{
    vector_t* vector_value = *vector;
    if (vector_value->capacity <= vector_value->length){
        vector_value->capacity += 5;
        realloc(vector_value->begin, vector_value->capacity * sizeof(data));
    }
    vector_value->begin[vector_value->length] = data;
    ++vector_value->length;
    vector = &vector_value;
}

void pop_back(vector_t **vector)
{
    vector_t* vector_value = *vector;
    if (vector_value->capacity >= vector_value->length + 10){
        vector_value->capacity -= 10;
        realloc(vector_value->begin, vector_value->capacity * sizeof(int));
    }
    --vector_value->length;
    vector = &vector_value;
}

void insert(vector_t** vector, int index, int data)
{
    vector_t* vector_value = *vector;
    if (vector_value->capacity <= vector_value->length){
        vector_value->capacity += 5;
        realloc(vector_value->begin, vector_value->capacity * sizeof(data));
    }
    for (int i = 0; i < vector_value->length - index; ++i) {
        vector_value->begin[vector_value->length - i] = vector_value->begin[vector_value->length - i - 1];
    }
    vector_value->begin[index + 1] = data;
    ++vector_value->length;
    vector = &vector_value;
}

int delete(vector_t** vector, int index)
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
        realloc(vector_value->begin, vector_value->capacity * sizeof(int));
    }
    --vector_value->length;
    vector = &vector_value;
    return 1;
}

int size(vector_t* vector)
{
    return  vector->length;
}

int capacity(vector_t* vector)
{
    return  vector->capacity;
}

int empty(vector_t* vector)
{
    if(vector->length == 0){
        return 1;
    } else {
        return 0;
    }
}

void print(vector_t* vector)
{
    for (int i = 0; i < vector->length; ++i) {
        printf("%d. %d\n", i + 1, vector->begin[i]);
    }
}

int search(vector_t* vector, int data)
{
    for (int i = 0; i < vector->length; ++i) {
        if (vector->begin[i] == data){
            return i;
        }
    }
    return -1;
}