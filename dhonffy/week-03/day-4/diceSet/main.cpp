#include <iostream>
#include "diceSet.h"
#include <time.h>

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    DiceSet diceSet;
    diceSet.roll();
    std::vector<int> current = diceSet.getCurrent();
    for (int i = 0; i < 6; ++i) {
        while (current[i] != 6)  {
                diceSet.roll(i);
                current[i] = diceSet.getCurrent(i);
        }
    }
    for (int i = 0; i < 6; ++i) {
        std::cout << i << " " << current[i] << std::endl;
    }
    return 0;
}
