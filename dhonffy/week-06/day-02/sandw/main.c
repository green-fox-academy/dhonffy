#include <stdio.h>
#include "order_sandwiches.h"
#include "string.h"

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

int main()
{
    sandwich_t fish_sandwich;

    strcpy(fish_sandwich.name, "fish");
    fish_sandwich.price = 2.99;
    fish_sandwich.weight = 30;
    printf("Your order costs %.2f euros", order_sandwiches(fish_sandwich, 3));
    return 0;
}

