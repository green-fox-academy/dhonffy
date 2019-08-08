#include <stdio.h>
#include "linked_list.h"

int main()
{

    node_t *head;
    init(&head);

    push_back(&head, 6);
    push_back(&head, 9);
    push_back(&head, 45);
    push_back(&head, 2346);
    push_back(&head, 0);
    push_front(&head, 42);
    insert(&head, 99, 3);
    insert(&head, 10, 0);


    print(head);
    return 0;
}