#include <stdio.h>
#include "print_car.h"
// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level


int main()
{
    car_t volvo;
    volvo.type = VOLVO;
    volvo.km = 123456;
    volvo.gas = 34.123;
    print_car(volvo);

    car_t toyota;
    toyota.type = TOYOTA;
    toyota.km = 999999;
    toyota.gas = 22.7;
    print_car(toyota);

    car_t land_rover;
    land_rover.type = LAND_ROVER;
    land_rover.km = 174745;
    land_rover.gas = 96;
    print_car(land_rover);

    car_t tesla;
    tesla.type = TESLA;
    tesla.km = 46000;
    tesla.gas = 0;
    print_car(tesla);

    return 0;
}