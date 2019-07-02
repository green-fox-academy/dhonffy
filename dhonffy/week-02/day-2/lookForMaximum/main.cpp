#include <iostream>

int *findValue(int numbers[], int length);

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address
    // of it

    int elementsOfArray;
    std::cout << "Please, type the size of the array:" << std::endl;
    std::cin >> elementsOfArray;
    int biggest[elementsOfArray];
    for (int i = 0; i < elementsOfArray; ++i) {
        std::cout << "Please, type element No " << i + 1 << "." << std::endl;
        std::cin >> biggest[i];
    }
    int *ptr;
    ptr = findValue(biggest, sizeof(biggest) / sizeof(biggest[0]));
    std::cout << "value: " << *ptr << " address: " << ptr << std::endl;
    return 0;
}

int *findValue(int biggest[], int length)
{
    int biggestNumber = -2147483648;
    int *indexPtr = biggest;
    for (int i = 0; i < length; ++i) {
        if (biggest[i] >= biggestNumber) {
            *indexPtr = biggest[i];
            biggestNumber = biggest[i];
        }
    }
    return indexPtr;
}