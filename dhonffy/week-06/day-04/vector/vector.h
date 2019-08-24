#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct vector{
    int* begin;
    int capacity;
    int length;
} vector_t;

void init(vector_t** head);
void push_back(vector_t** head, int data);
void insert(vector_t** head, int element, int data);
void print(vector_t* vector);

#endif //VECTOR_VECTOR_H
