#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that prints a few operations on two numbers: 22 and 13

    std::cout << 22+13 << std::endl;// Print the result of 13 added to 22

    std::cout << 22-13 << std::endl;// Print the result of 13 substracted from 22

    std::cout << 22*13 << std::endl;// Print the result of 22 multiplied by 13

    std::cout << static_cast<float> (22) / 13  << std::endl;// Print the result of 22 divided by 13 (as a decimal fraction)

    std::cout << 22/13 << std::endl;// Print the integer part of 22 divided by 13

    std::cout << 22%13 << std::endl;// Print the remainder of 22 divided by 13

    return 0;
}