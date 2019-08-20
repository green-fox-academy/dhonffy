#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

typedef struct node{
    int data;
    struct node* next;
} node_t;

void init(node_t** head);
void push_back(node_t** head, int data);
void push_front(node_t** head, int data);
void insert(node_t** head, int data, int element);
void print(node_t* head);
int size(node_t* head);
int empty(node_t* head);
void pop_front(node_t* head);
int remove_if(node_t* head, int value);
void delete_after(node_t** head, int element);

#endif //LINKED_LIST_LINKED_LIST_H