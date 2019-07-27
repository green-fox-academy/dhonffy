#include <iostream>
#include "Bird.h"

Bird::Bird(const std::string &name) : Animal(name)
{

}

std::string Bird::getName()
{
    return _name;
}

std::string Bird::breed()
{
    return "laying eggs.";
}

void Bird::land()
{
    std::cout << "I'm flyable, I can land." << std::endl;
}

void Bird::fly()
{
    std::cout << "I'm flyable, I can fly." << std::endl;
}

void Bird::takeOff()
{
    std::cout << "I'm flyable, I can take off." << std::endl;
}
