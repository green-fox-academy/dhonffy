
#ifndef THEGARDENAPPLICATION_GARDEN_H
#define THEGARDENAPPLICATION_GARDEN_H

#include <vector>
#include "Plant.h"

class Garden
{
public:
    Garden();

    void watering(float amount);
    void addPlant(Plant* plant);
    void info();
private:
    std::vector<Plant> _plants;
};


#endif //THEGARDENAPPLICATION_GARDEN_H
