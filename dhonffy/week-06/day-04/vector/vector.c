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

void pop_back(vector_t **head)
{
    vector_t* head_value = *head;
    if (head_value->capacity >= head_value->length + 10){
        head_value->capacity -= 10;
        realloc(head_value->begin, head_value->capacity * sizeof(int));
    }
    --head_value->length;
    head = &head_value;
}

void insert(vector_t** head, int index, int data)
{
    vector_t* head_value = *head;
    if (head_value->capacity <= head_value->length){
        head_value->capacity += 5;
        realloc(head_value->begin, head_value->capacity * sizeof(data));
    }
    for (int i = 0; i < head_value->length - index; ++i) {
        head_value->begin[head_value->length - i] = head_value->begin[head_value->length - i - 1];
    }
    head_value->begin[index + 1] = data;
    ++head_value->length;
    head = &head_value;
}

int delete(vector_t** head, int index)
{
    vector_t* head_value = *head;
    if(index >= head_value->length){
        return 0;
    }
    for (int i = index; i < head_value->length; ++i) {
        head_value->begin[i] = head_value->begin[i + 1];
    }
    if (head_value->capacity >= head_value->length + 10){
        head_value->capacity -= 10;
        realloc(head_value->begin, head_value->capacity * sizeof(int));
    }
    --head_value->length;
    head = &head_value;
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