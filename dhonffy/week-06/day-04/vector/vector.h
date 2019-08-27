#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct vector{
    int* begin;
    int capacity;
    int length;
} vector_t;

void init(vector_t** head);
void push_back(vector_t** head, int data);
void pop_back(vector_t** head);
void insert(vector_t** head, int index, int data);
int delete(vector_t** head, int index);
void print(vector_t* vector);
int size(vector_t* vector);
int capacity(vector_t* vector);
int empty(vector_t* vector);
int search(vector_t* vector, int data);

#endif //VECTOR_VECTOR_H
