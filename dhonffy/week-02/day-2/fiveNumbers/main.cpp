#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again
    int numbers[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << "Please, type a number:";
        std::cin >> numbers[i];
    }
    int *numbersPtr = numbers;
    for (int j = 0; j < 5; ++j) {
        std::cout << *(numbersPtr + j) << std::endl;
    }
    return 0;
}