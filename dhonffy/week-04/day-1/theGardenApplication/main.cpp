#include <iostream>
#include "Flower.h"
#include "Tree.h"

int main()
{
    Flower yellowFlower = Flower(color::YELLOW);
    Tree purpleTree = Tree(color::PURPLE);
    std::cout << yellowFlower.needsWater() << std::endl;
    std::cout << purpleTree.needsWater() << std::endl;
    yellowFlower.watering(5);
    purpleTree.watering(5);
    std::cout << yellowFlower.needsWater() << std::endl;
    std::cout << purpleTree.needsWater() << std::endl;
    yellowFlower.watering(5);
    purpleTree.watering(5);
    std::cout << yellowFlower.needsWater() << std::endl;
    std::cout << purpleTree.needsWater() << std::endl;
    yellowFlower.watering(1);
    purpleTree.watering(20);
    std::cout << yellowFlower.needsWater() << std::endl;
    std::cout << purpleTree.needsWater() << std::endl;

    return 0;
}