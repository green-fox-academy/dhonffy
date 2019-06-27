#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    int chicken;
    int pig;
    std::cout << "How many chickens has the farmer?" << std::endl;
    std::cin >> chicken;
    std::cout << "How many pigs has the farmer?" << std::endl;
    std::cin >> pig;

    // It should print how many legs all the animals have
    std::cout << "There are " << (chicken * 2 + pig * 4) << " animal legs.";

    return 0;
}