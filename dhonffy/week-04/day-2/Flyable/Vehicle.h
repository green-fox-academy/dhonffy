#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H


class Vehicle
{
public:
    virtual void addFuel() = 0;
    virtual void drive() = 0;
    virtual void turn() = 0;
};


#endif //FLYABLE_VEHICLE_H
