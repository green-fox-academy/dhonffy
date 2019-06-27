#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4

    int number1;
    int number2;
    int number3;
    int number4;
    int number5;
    int sum;
    std::cout << "Please, type the first integer!" << std::endl;
    std::cin >> number1;

    std::cout << "Please, type the second integer!" << std::endl;
    std::cin >> number2;

    std::cout << "Please, type the third integer!" << std::endl;
    std::cin >> number3;

    std::cout << "Please, type the fourth integer!" << std::endl;
    std::cin >> number4;

    std::cout << "Please, type the fifth integer!" << std::endl;
    std::cin >> number5;

    sum =number1 + number2 + number3 + number4 + number5;
    std::cout << "Sum: " << sum << ", Average: " << (sum / 5) << std::endl;
    return 0;
}