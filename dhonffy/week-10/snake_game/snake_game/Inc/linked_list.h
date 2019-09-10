#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include "declare.h"
linked_list_node_t* linked_list_create();
void linked_list_deallocate(linked_list_node_t **head);
void linked_list_push_back(linked_list_node_t **head, coord_t data);
void linked_list_push_front(linked_list_node_t **head, coord_t data);
coord_t linked_list_pop_back(linked_list_node_t **head);
#endif //__LINKED_LIST_H
