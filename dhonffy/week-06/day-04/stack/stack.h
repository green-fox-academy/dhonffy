#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef struct stack{
    int* begin;
    int capacity;
    int length;
} stack_t;

void init(stack_t** stack);
void push(stack_t** stack, int data);
void pop(stack_t** stack);
int empty(stack_t* vector);

#endif //STACK_STACK_H
