#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number form the standard input,
    int a;
    std::cout << "Please type a number!" << std::endl;
    std::cin >> a;
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot
    switch (a) {
        case 1:
            std::cout << "One" << std::endl;
            break;
        case 2:
            std::cout << "Two" << std::endl;
            break;
        default:
            if (a > 0) {
                std::cout << "A lot" << std::endl;
            }else{
                std::cout << "Not enough" << std::endl;
            }
    }
    return 0;
}