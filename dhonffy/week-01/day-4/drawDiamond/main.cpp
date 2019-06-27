#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int allRows;
    std::cout << "Please, type a number!" << std::endl;
    std::cin >> allRows;
    for (int actRow = 1; actRow <= allRows ; ++actRow) {
        if (actRow <= ((allRows / 2 ) + 1)) {
            for (int spaces = 0; spaces < (allRows - actRow); ++spaces) {
                std::cout << " ";
            }
            std::cout << "*";
            if (actRow > 1) {
                for (int stars = 0; stars < (actRow - 1); ++stars) {
                    std::cout << "**";
                }
            }
        } else {
            for (int spaces = (allRows - actRow); spaces > 0 ; --spaces) {
                std::cout << " ";
            }
            for (int stars = (actRow - 1); stars > 1; --stars) {
                std::cout << "**";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}