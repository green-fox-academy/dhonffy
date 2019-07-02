#include <iostream>

int *minimumValue(int numbers[], int length);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int minimumValueInt;
    std::cout << *minimumValue(numbers, sizeof(numbers) / sizeof(numbers[0])) << std::endl;
    return 0;
}

int *minimumValue(int numbers[], int length)
{
    int minimumValue = numbers[0];
    int *minimumValuePtr = &minimumValue;
    for (int i = 1; i < length; ++i) {
        if (numbers[i] < minimumValue) {
            minimumValue = numbers[i];
        }
    }
    return minimumValuePtr;
}