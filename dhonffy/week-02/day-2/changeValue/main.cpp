#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *tempPointer = &temperature;
    *tempPointer = 21.9;
    std::cout << temperature << std::endl;
    return 0;
}