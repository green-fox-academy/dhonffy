#include <iostream>
#include "Garden.h"

Garden::Garden()
{}

void Garden::watering(float amount)
{
    std::cout << "Watering with " << amount << std::endl;
    for (int i = 0; i < _plants.size(); ++i) {
        _plants[i].watering(amount / _plants.size());
    }
}

void Garden::addPlant(Plant* plant)
{
    _plants.push_back(*plant);
}

void Garden::info()
{
    for (int i = 0; i < _plants.size(); ++i) {
        std::cout << _plants[i].needsWater() << std::endl;
    }
}
