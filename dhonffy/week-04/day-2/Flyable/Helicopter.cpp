#include "Helicopter.h"
#include <iostream>
void Helicopter::land()
{
    std::cout << "I'm flyable, I can land." << std::endl;
}

void Helicopter::fly()
{
    std::cout << "I'm flyable, I can fly." << std::endl;
}

void Helicopter::takeOff()
{
    std::cout << "I'm flyable, I can take off." << std::endl;
}

void Helicopter::addFuel()
{
    std::cout << "I'm a vehicle, fuel can be added to me." << std::endl;
}

void Helicopter::drive()
{
    std::cout << "I'm a vehicle, I can be driven." << std::endl;
}

void Helicopter::turn()
{
    std::cout << "I'm a vehicle, I can turn." << std::endl;
}
