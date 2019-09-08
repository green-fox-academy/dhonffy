#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct vector{
    int* begin;
    int capacity;
    int length;
} vector_t;

void vector_init(vector_t** vector);
void vector_push_back(vector_t** vector, int data);
void vector_pop_back(vector_t** vector);
void vector_insert(vector_t** vector, int index, int data);
int vector_delete(vector_t** vector, int index);
void vector_print(vector_t* vector);
int vector_size(vector_t* vector);
int vector_capacity(vector_t* vector);
int vector_empty(vector_t* vector);
int vector_search(vector_t* vector, int data);
int vector_get(vector_t* vector, int index);

#endif //VECTOR_VECTOR_H
