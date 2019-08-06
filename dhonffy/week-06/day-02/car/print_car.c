#include "print_car.h"

void print_car(struct car car)
{
    printf("car type: %s, km: %.0f", sayCarType(car.type), car.km);
    if (car.type != TESLA){
        printf(", gas amount %.1f", car.gas);
    }
    printf("\n");
}

char *sayCarType(int car)
{
    switch (car) {
        case 0: return "Volvo";
        case 1: return "Toyota";
        case 2: return "Land Rover";
        case 3: return "Tesla";
    }
}