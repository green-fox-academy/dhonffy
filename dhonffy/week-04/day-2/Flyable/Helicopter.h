#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "flyable.h"
#include "vehicle.h"

class Helicopter : Vehicle, Flyable
{
    void land() override;

    void fly() override;

    void takeOff() override;

    void addFuel() override;

    void drive() override;

    void turn() override;
};


#endif //FLYABLE_HELICOPTER_H
