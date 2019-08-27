#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void init(vector_t** head)
{
    vector_t* head_value = *head;
    head = NULL;
    head_value->length = 0;
    head_value->capacity = 1;
    head_value->begin = (int *) malloc(sizeof(int));
    head = &head_value;
}

void push_back(vector_t **head, int data)
{
    vector_t* head_value = *head;
    if (head_value->capacity <= head_value->length){
        head_value->capacity += 5;
        realloc(head_value->begin, head_value->capacity * sizeof(data));
    }
    head_value->begin[head_value->length] = data;
    ++head_value->length;
    head = &head_value;
}

void insert(vector_t** head, int element, int data)
{
    vector_t* head_value = *head;
    if (head_value->capacity <= head_value->length){
        head_value->capacity += 5;
        realloc(head_value->begin, head_value->capacity * sizeof(data));
    }
    for (int i = 0; i < head_value->length - element; ++i) {
        head_value->begin[head_value->length - i] = head_value->begin[head_value->length - i - 1];
    }
    head_value->begin[element + 1] = data;
    ++head_value->length;
    head = &head_value;
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
    int counter = vector->length;
    for (int i = 0; i < vector->length; ++i) {
        printf("%d. %d\n", i + 1, vector->begin[i]);
    }
}