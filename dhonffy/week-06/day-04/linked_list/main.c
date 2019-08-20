#include <stdio.h>
#include "linked_list.h"

int main()
{

    node_t *head;
    init(&head);
    empty(head) ? printf("The vector is empty.\n") : printf("The vector is not empty.\n");
    push_back(&head, 6);
    print(head);
    printf("The size of the vector is: %d.\n", size(head));
    empty(head) ? printf("The vector is empty.\n") : printf("The vector is not empty.\n");
    push_back(&head, 9);
    push_back(&head, 45);
    push_back(&head, 2346);
    push_back(&head, 0);
    push_front(&head, 42);
    insert(&head, 99, 3);
    insert(&head, 10, 0);
    print(head);
    printf("The size of the vector is: %d.\n", size(head));
    pop_front(head);
    print(head);
    printf("The size of the vector is: %d.\n", size(head));

    delete_after(&head, 0);
    print(head);
    printf("The size of the vector is: %d.\n", size(head));

    return 0;
}