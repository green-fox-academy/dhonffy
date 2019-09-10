#include "linked_list.h"
#include "main.h"

linked_list_node_t* linked_list_create()
{
  return NULL;
}

void linked_list_deallocate(linked_list_node_t **head)
{
  linked_list_node_t *p;
  while(*head != NULL){
	p = *head;
    head = (*head)->next;
    vPortFree(p);
  }
}

void linked_list_push_back(linked_list_node_t **head, coord_t data)
{
  linked_list_node_t* new_node = (linked_list_node_t*) pvPortMalloc(sizeof(linked_list_node_t));
  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL) {
	*head = new_node;
	return;
  }

  linked_list_node_t *p = *head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = new_node;
}

void linked_list_push_front(linked_list_node_t **head, coord_t data)
{
  linked_list_node_t* new_head = (linked_list_node_t*) pvPortMalloc(sizeof(linked_list_node_t));
  new_head->next = *head;
  new_head->data = data;
  *head = new_head;
}

coord_t linked_list_pop_back(linked_list_node_t **head)
{
  ++test1;
  linked_list_node_t *p = *head;
  ++test2;
  while (p->next != NULL) {
	  ez így ratyi az előző nextjét is át kéne írni n-ra nem csak freeelni
    ++test3;
	p = p->next;
  }
  ++test4;
  coord_t deleted_element = p->data;
  vPortFree(p);
  return deleted_element;
}

uint8_t linked_list_size(linked_list_node_t *head)
{
  uint8_t counter = 0;
  linked_list_node_t *p = head;
  while (p != NULL) {
    p = p->next;
    ++counter;
  }
  return counter;
}

uint8_t linked_list_get_x(linked_list_node_t *head, uint8_t index)
{
  uint8_t counter = 0;
  linked_list_node_t *p = head;
  while (counter != index) {
    p = p->next;
    ++counter;
  }
  return p->data.x;
}

uint8_t linked_list_get_y(linked_list_node_t *head, uint8_t index)
{
  uint8_t counter = 0;
  linked_list_node_t *p = head;
  while (counter != index) {
    p = p->next;
    ++counter;
  }
  return p->data.y;
}
