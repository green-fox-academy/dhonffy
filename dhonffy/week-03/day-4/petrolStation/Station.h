#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H

#include <iostream>
#include "Car.h"

class Station
{
public:
    Station(int gasAmount);
    void fill(Car& car);
    void remain();

private:
    int _gasAmount;
};


#endif //PETROLSTATION_STATION_H
