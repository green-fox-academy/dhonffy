#ifndef THEGARDENAPPLICATION_FLOWER_H
#define THEGARDENAPPLICATION_FLOWER_H


#include "Plant.h"

class Flower : public Plant
{
public:
    Flower(color color);

    void watering(int amount) override;

    bool needsWater() override;
};


#endif //THEGARDENAPPLICATION_FLOWER_H
