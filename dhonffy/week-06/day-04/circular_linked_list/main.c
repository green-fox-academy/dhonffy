#include <stdio.h>
#include "circular_linked_list.h"
int main()
{
    node_t* current;
    init(&current, 8);
    current = write(current, 1);
    current = write(current, 2);
    current = write(current, 3);
    current = write(current, 4);
    current = write(current, 5);
    current = write(current, 5);
    printf("%d\n", is_below_threshold(current, 6));
    current = write(current, 55);
    current = write(current, 5);
    printf("%d\n", is_below_threshold(current, 6));
    printf("%d\n", is_below_threshold(current, 88));
    add_node(current, 3, 99);
    printf("%d\n", is_below_threshold(current, 2));
    printf("%d\n", is_below_threshold(current, 88));
    add_node(current, 102, 105);
    printf("%d\n", is_below_threshold(current, 102));
    remove_node(current, 99);
    printf("%d\n", is_below_threshold(current, 88));


    return 0;
}