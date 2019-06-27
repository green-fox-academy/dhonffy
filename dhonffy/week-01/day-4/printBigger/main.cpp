#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int number1;
    int number2;
    std::cout << "Please, type the first number!" << std::endl;
    std::cin >> number1;
    std::cout << "Please, type the second number!" << std::endl;
    std::cin >> number2;
    if (number1 > number2){
        std::cout << "The bigger number is " << number1 << std::endl;
    } else {
        std::cout << "The bigger number is " << number2 << "." << std::endl;
    }
    return 0;
}