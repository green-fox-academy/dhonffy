#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

float calculate_area(float radius);
int main()
{
    printf("The area of the square is: %f", calculate_area(3.14));
    return 0;
}

float calculate_area(float radius)
{
    return radius * radius * PI;
}