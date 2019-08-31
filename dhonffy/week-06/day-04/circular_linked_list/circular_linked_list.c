#include "circular_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void add_head(node_t** head)
{
    *head = NULL;
}

void init(node_t** head, int size)
{
    node_t *end_node = (node_t *) malloc(sizeof(node_t));
    end_node->data = 0;
    node_t* next_node = end_node;
    node_t* node;
    for (int i = 0; i < size; ++i) {
        node = (node_t *) malloc(sizeof(node_t));
        node->data = 0;
        node->next = next_node;
        next_node = node;
    }
    head = &node;
    end_node->next = node;
}


void add_node_by_index(node_t** head, int index)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = 0;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *p = *head;
    int counter = 0;
    while (p->next != NULL) {
        p = p->next;
        if (counter++ == index){
            p->next = *head;
        }
    }

    p->next = new_node;
}

void write(int data, node_t* current)
{

}


/*
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

void pop_front(node_t **head)
{
    node_t* next_node = *head;
    free(head);
    *head = next_node->next;
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

int remove_if(node_t** head, int value)
{
    int counter = 0;
    int deleted_elements = 0;
    node_t* p = *head;
    node_t* previous_node = NULL;
    while (p != NULL) {
        if (value == p->data) {
            if (counter == 0) {
                node_t* next_node = *head;
                free(head);
                *head = next_node->next;
                //pop_front(head);
                p = *head;
            } else {
                node_t* node_to_delete = previous_node->next;
                if (node_to_delete != NULL) {
                    previous_node->next = node_to_delete->next;
                    free(node_to_delete);
                    p = previous_node;
                }
            }
            ++deleted_elements;
        } else {
            ++counter;
            previous_node = p;
            p = p->next;
        }
    }
    return deleted_elements;
}

void delete_after(node_t **head, int element)
{
    node_t *p = *head;
    for (int i = 0; i < element; ++i) {
        p = p->next;
    }
    node_t* node_to_delete = p->next;
    if (p->next != NULL) {
        p->next = node_to_delete->next;
        free(node_to_delete);
    }
}

node_t* search(node_t* head, int value)
{
    node_t *p = head;
    while (p != NULL) {
        if (value == p->data) {
            return p;
        }
        p = p->next;
    }
}

void sort_bubble(node_t* head)
{
    if (head == NULL){
        return;
    }
    int sorted = 0;
    do {
        node_t* left = head;
        if (left->next == NULL) {
            return;
        }
        node_t* right = left->next;
        sorted = 0;
        do {
            if (left->data > right->data) {
                int temp = left->data;
                left->data = right->data;
                right->data = temp;
                sorted = 1;
            }
            left = right;
            right = right->next;
        } while (right != NULL);
    } while (sorted == 1);
}

void sort_insertion(node_t* head)
{
    if (head == NULL){
        return;
    }
    pointer_node_t* pointer_head;
    pointer_init(&pointer_head);

}*/