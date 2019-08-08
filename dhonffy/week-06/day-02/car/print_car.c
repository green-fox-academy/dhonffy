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
        case VOLVO: return "Volvo";
        case TOYOTA: return "Toyota";
        case LAND_ROVER: return "Land Rover";
        case TESLA: return "Tesla";
    }
}