#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5
    int number1;
    int number2;

    std::cout << "Please type the first number!" << std::endl;
    std::cin >> number1;
    std::cout << "Please type the second number!" << std::endl;
    std::cin >> number2;

    if (number2 <= number1) {
        std::cout << "The second number should be bigger" << std::endl;
    } else {
        for (int i = number1; i < number2; ++i) {
            std:: cout << i << std::endl;
        }
    }

    return 0;
}