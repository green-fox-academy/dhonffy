#include <iostream>
#include <fstream>
#include <exception>

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    int ten = 10;
    int number;
    std::cout << "Please type a number! " << std::endl;
    std::cin >> number;
    try {
        if (number == 0) {
            throw std::string("Can't devide by 0");
        }
        std::cout << ten / number << std::endl;
    } catch  (std::string& e) {
        std::cout << e << std::endl;
    }
    return 0;
}