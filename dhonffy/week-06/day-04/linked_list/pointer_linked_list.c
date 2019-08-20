#include "pointer_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void pointer_init(pointer_node_t **head)
{
    *head = NULL;
}

void pointer_push_back(pointer_node_t **head, node_t* data)
{
    pointer_node_t *new_node = (pointer_node_t *) malloc(sizeof(pointer_node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    pointer_node_t *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
}

