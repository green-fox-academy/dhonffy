#ifndef SANDW_ORDER_SANDWICHES_H
#define SANDW_ORDER_SANDWICHES_H

typedef struct Sandwich {
    char name[20];
    float price;
    float weight;
} sandwich_t;
float order_sandwiches(sandwich_t, int);

#endif //SANDW_ORDER_SANDWICHES_H
