#ifndef CAR_PRINT_CAR_H
#define CAR_PRINT_CAR_H

#include <stdio.h>
enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

typedef struct car {
    enum car_type type;
    double km;
    double gas;
} car_t;

void print_car(struct car);

char* sayCarType(int);
#endif //CAR_PRINT_CAR_H
