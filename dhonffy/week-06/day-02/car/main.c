#include <stdio.h>
#include "print_car.h"
// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level


int main()
{
    car_t volvo = {VOLVO, 123456, 34.123};
    print_car(volvo);

    car_t toyota = {TOYOTA, 999999, 22.7};
    print_car(toyota);

    car_t land_rover = {LAND_ROVER, 174745 ,96};
    print_car(land_rover);

    car_t tesla = {TESLA, 46000, 0};
    print_car(tesla);

    return 0;
}