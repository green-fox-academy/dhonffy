#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

typedef struct node{
    int data;
    struct node* next;
} node_t;

void add_head(node_t** head);
void add_node_by_index(node_t** node, int index);
void init(node_t** head, int size);
void write(int data, node_t* current);


/*
void push_back(node_t** head, int data);
void push_front(node_t** head, int data);
void insert(node_t** head, int data, int element);
void print(node_t* head);
int size(node_t* head);
int empty(node_t* head);
void pop_front(node_t** head);
int remove_if(node_t** head, int value);
void delete_after(node_t** head, int element);
node_t* search(node_t* head, int value);
void sort_bubble(node_t* head);
void sort_insertion(node_t* head);
*/
#endif //LINKED_LIST_LINKED_LIST_H