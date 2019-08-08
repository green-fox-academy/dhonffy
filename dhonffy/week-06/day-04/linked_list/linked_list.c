#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void init(node_t **head)
{
    *head = NULL;
}

void push_back(node_t **head, int data)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
}

void push_front(node_t **head, int data)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert(node_t **head, int data, int element)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    node_t *p = *head;
    node_t *nextNode = *head;
    for (int i = 0; i < element; ++i) {
        p = p->next;
    }
    nextNode = p->next;
    p->next = new_node;
    new_node->next = nextNode;
}

void size(node_t* head)
{

}

void print(node_t *head)
{
    int counter = 0;
    while (head != NULL) {
        printf("%d. %d\n", ++counter, head->data);
        head = head->next;
    }
}