#include "Flower.h"


Flower::Flower(color color) : Plant(color, type::FLOWER)
{

}

void Flower::watering(int amount)
{
    _waterAmount += 0.75 * amount;
}

bool Flower::needsWater()
{
    return (_waterAmount < 5.0 ? true : false);
}
