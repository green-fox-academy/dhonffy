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
    node_t *next_node = *head;
    for (int i = 0; i < element; ++i) {
        p = p->next;
    }
    next_node = p->next;
    p->next = new_node;
    new_node->next = next_node;
}

int size(node_t *head)
{
    int counter = 0;
    while (head != NULL) {
        ++counter;
        head = head->next;
    }
    return counter;
}

int empty(node_t *head)
{
    if (head == NULL) {
        return 1;
    }
    return 0;
}

void print(node_t *head)
{
    int counter = 0;
    while (head != NULL) {
        printf("%d. %d\n", ++counter, head->data);
        head = head->next;
    }
}

void pop_front(node_t *head)
{
    struct node *new_head = head->next;
    free(head);
    *head = *new_head;
}

int remove_if(node_t *head, int value)
{
    int first_element = 1;
    int deleted_elements = 0;
    node_t previous_element;
    while (head != NULL) {
        if (value == head->data) {
            if (first_element == 1) {
                pop_front(head);
                head = head->next;
            } else {
                previous_element.next = head->next;
                free(head);
                *head = previous_element;
            }
            ++deleted_elements;
        } else {
            first_element = 0;
            previous_element = *head;
        }
        head = head->next;
    }
    return deleted_elements;
}

void delete_after(node_t **head, int element)
{
    node_t *p = *head;
    node_t *node_to_delete = *head;
    for (int i = 0; i < element; ++i) {
        p = p->next;
    }
    node_to_delete = p->next;
    if (p->next != NULL) {
        p->next = node_to_delete->next;
        free(node_to_delete);
    }
}
