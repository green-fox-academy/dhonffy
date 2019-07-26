#ifndef THEGARDENAPPLICATION_TREE_H
#define THEGARDENAPPLICATION_TREE_H

#include "Plant.h"

class Tree : public Plant
{
public:
    Tree(color color);

    void watering(int amount) override;

    bool needsWater() override;
};

#endif //THEGARDENAPPLICATION_TREE_H
