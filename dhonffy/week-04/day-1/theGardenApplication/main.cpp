#include <iostream>
#include "Flower.h"
#include "Tree.h"
#include "Garden.h"

int main()
{
    Garden centralPark;
    Flower yellowFlower = Flower(color::YELLOW);
    Flower blueFlower = Flower(color::BLUE);
    Tree purpleTree = Tree(color::PURPLE);
    Tree orangeTree = Tree(color::ORANGE);
    centralPark.addPlant(&yellowFlower);
    centralPark.addPlant(&blueFlower);
    centralPark.addPlant(&purpleTree);
    centralPark.addPlant(&orangeTree);
    centralPark.watering(40);
    centralPark.info();
    centralPark.watering(70);
    centralPark.info();

    return 0;
}