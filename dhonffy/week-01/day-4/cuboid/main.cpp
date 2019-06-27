#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double a = 3;
    double b = 4;
    double c = 5;

    std::cout << "Surface area: " << (2 * a * b + 2 * a * c + 2 * b * c) << std::endl;
    std::cout << "Volume: " << ( a * b * c) << std::endl;

    return 0;
}