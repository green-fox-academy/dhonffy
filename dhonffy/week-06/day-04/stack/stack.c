#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void init(stack_t** stack)
{
    stack_t* stack_value = *stack;
    stack = NULL;
    stack_value->length = 0;
    stack_value->capacity = 1;
    stack_value->begin = (int *) malloc(sizeof(int));
    stack = &stack_value;
}

void push_back(stack_t **stack, int data)
{
    stack_t* stack_value = *stack;
    if (stack_value->capacity <= stack_value->length){
        stack_value->capacity += 5;
        realloc(stack_value->begin, stack_value->capacity * sizeof(data));
    }
    stack_value->begin[stack_value->length] = data;
    ++stack_value->length;
    stack = &stack_value;
}

void pop(stack_t **stack)
{
    stack_t* stack_value = *stack;
    if (stack_value->capacity >= stack_value->length + 10){
        stack_value->capacity -= 10;
        realloc(stack_value->begin, stack_value->capacity * sizeof(int));
    }
    --stack_value->length;
    stack = &stack_value;
}

int empty(stack_t* stack)
{
    if(stack->length == 0){
        return 1;
    } else {
        return 0;
    }
}

int get(stack_t* stack)
{
    return stack->begin[stack->length];
}
