#include <iostream>

int bunnies(int bunny);

int main()
{
//    We have a number of bunnies and each bunny has two big floppy ears. We want to
//    compute the total number of ears across all the bunnies recursively (without loops
//    or multiplication).
    std::cout << bunnies(100) << std::endl;
    return 0;
}

int bunnies(int bunny)
{
    int ears = 0;
    if (bunny >= 1){
        ears = 2 + bunnies(bunny - 1);
    }
    return ears;
}