#include <stdio.h>
#include "stack.h"
int main()
{
    stack_t* stack;
    init(&stack);
    printf("The stack is empty: %d \n", empty(stack));
    push(&stack, 8);
    printf("The stack is empty: %d \n", empty(stack));
    push(&stack, 88);
    pop(&stack);
    push(&stack, 3);
    printf("top of the stack: %d.\n", get(stack));
    push(&stack, 108);
    push(&stack, 95);
    printf("top of the stack: %d.\n", get(stack));
    printf("The stack is empty: %d \n", empty(stack));
    push(&stack, 1985);
    push(&stack, 1985);
    push(&stack, 1985);
    printf("top of the stack: %d.\n", get(stack));
    push(&stack, 1985);
    push(&stack, 1985);
    push(&stack, 1985);
    push(&stack, 1985);
    push(&stack, 1985);
    push(&stack, 1985);
    push(&stack, 1985);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("top of the stack: %d.\n", get(stack));
    pop(&stack);
    printf("top of the stack: %d.\n", get(stack));

//    free(stack);

    return 0;
}