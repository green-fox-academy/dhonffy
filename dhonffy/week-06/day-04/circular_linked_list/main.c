#include <stdio.h>
#include "circular_linked_list.h"
int main()
{
    node_t* current;
    init(&current, 8);
    write(current, 1);
    write(current, 2);
    write(current, 3);
    write(current, 4);
    write(current, 5);
    write(current, 5);
    write(current, 5);
    write(current, 5);
    printf("%d\n", is_below_threshold(current, 10));
    return 0;
}