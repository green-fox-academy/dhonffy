#include <stdio.h>
#include "sandwich_order.h"
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
struct Sandwich {
    char* name;
    float price;
    float weight;
};


int main()
{
    struct Sandwich fish_sandwich{
        name = fish;
        price = 2.99;
        weight = 30;
    };
    printf("Your order costs %f euros", order_sandwiches(fish_sandwich, 3));
    return 0;
}

float order_sandwiches(struct Sandwich sandwich, int amount)
{
    return sandwich.price * (float)amount;
}