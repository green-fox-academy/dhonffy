#ifndef LINKED_LIST_POINTER_LINKED_LIST_H
#define LINKED_LIST_POINTER_LINKED_LIST_H
#include "linked_list.h"

typedef struct pointer_node{
    node_t* data;
    struct pointer_node* next;
} pointer_node_t;

void pointer_init(pointer_node_t** head);
void pointer_push_back(pointer_node_t** head, node_t* data);
#endif //LINKED_LIST_POINTER_LINKED_LIST_H
