#include <stdio.h>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float* temperature_pointer = &temperature;
    *temperature_pointer = 21.4;
    printf("%.1f\n", *temperature_pointer);
    printf("%.1f\n", temperature);
    return 0;
}