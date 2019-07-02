#include <iostream>

int *findValue(int numbers[], int length, int parameter);

int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a
    // parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int whatToFind = 101;
    std::cout << *findValue(numbers, sizeof(numbers) / sizeof(numbers[0]), whatToFind) << std::endl;
    return 0;
}

int *findValue(int numbers[], int length,  int parameter)
{
    int index = -1;
    int *indexPtr = &index;
    for (int i = 0; i < length ; ++i) {
        if (numbers[i] == parameter) {
            index = i;
        }
    }
    return indexPtr;
}