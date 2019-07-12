#include <iostream>

int bunnies2(int bunny);
int bunnies3(int bunny);

int main()
{
    //We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
    //(1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
    //have 3 ears, because they each have a raised foot. Recursively return
    // the number of "ears" in the bunny line 1, 2, ... n (without loops or
    // multiplication).
    std::cout << bunnies2(400) << std::endl;
    return 0;
}

int bunnies2(int bunny)
{
    int ears = 0;
    if (bunny >= 1){
        ears = 2 + bunnies3(bunny - 1);
    }
    return ears;
}

int bunnies3(int bunny)
{
    int ears = 0;
    if (bunny >= 1){
        ears = 3 + bunnies2(bunny - 1);
    }
    return ears;
}