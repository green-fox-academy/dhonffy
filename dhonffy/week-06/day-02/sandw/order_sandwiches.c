#include "order_sandwiches.h"
float order_sandwiches(sandwich_t sandwich, int amount)
{
    return sandwich.price * (float)amount;
}