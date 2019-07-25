#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include "Pirate.h"
#include <vector>

class ship
{
public:
    ship();

    void fillShip();
private:
    std::vector<Pirate> pirates;
    Pirate captain;
};


#endif //PIRATES_SHIP_H
