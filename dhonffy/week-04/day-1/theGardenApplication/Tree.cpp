
#include "Tree.h"


Tree::Tree(color color) : Plant(color, type::TREE)
{

}

void Tree::watering(int amount)
{
    _waterAmount += 0.4 * amount;
}

bool Tree::needsWater()
{
    return (_waterAmount < 10.0 ? true : false);
}
