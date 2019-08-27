#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct vector{
    int* begin;
    int capacity;
    int length;
} vector_t;

void init(vector_t** vector);
void push_back(vector_t** vector, int data);
void pop_back(vector_t** vector);
void insert(vector_t** vector, int index, int data);
int delete(vector_t** vector, int index);
void print(vector_t* vector);
int size(vector_t* vector);
int capacity(vector_t* vector);
int empty(vector_t* vector);
int search(vector_t* vector, int data);

#endif //VECTOR_VECTOR_H
