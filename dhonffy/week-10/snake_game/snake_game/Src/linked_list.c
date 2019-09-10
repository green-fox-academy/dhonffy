#include "linked_list.h"
#include "main.h"

linked_list_node_t* linked_list_create() {
  return NULL;
}

void linked_list_deallocate(linked_list_node_t *head) {
  linked_list_node_t *p;
  while(*head == NULL){
	*p = *head;
    *head = head->next;
    vPortFree(p);
  }
}

void push_back(linked_list_node_t **head, coord_t data) {
  linked_list_node_t* new_node = (linked_list_node_t*) pvPortMalloc(sizeof(linked_list_node_t));
  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL) {
	*head = new_node;
  }

linked_list_node_t *p = *head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = new_node;
}
