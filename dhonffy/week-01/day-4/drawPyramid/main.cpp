#include <iostream>

int main(int argc, char *args[])
{

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int allRows;
    std::cout << "Please, type a number!" << std::endl;
    std::cin >> allRows;
    for (int actRow = 1; actRow <= allRows; ++actRow) {
        for (int spaces = 0; spaces < (allRows - actRow); ++spaces) {
            std::cout << " ";
        }
        std::cout << "*";
        if (actRow > 1) {
            for (int stars = 0; stars < (actRow - 1); ++stars) {
                std::cout << "**";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}