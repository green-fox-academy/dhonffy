#include <iostream>
#include <vector>
#include "ship.h"
#include <ctime>

ship::ship()
{
    srand(time(NULL));
}

void ship::fillShip()
{
    Pirate captain;
    Pirate fillerPirate;
    std::vector<Pirate> pirates;
    int numberOfPirates = rand() % 50;
    for (int i = 0; i < numberOfPirates; ++i) {
        pirates.push_back(fillerPirate);
    }
}
