#include <stdio.h>
#include <stdlib.h>
#include "circumference.h"



//Continue working on the pi.c project

//Organize the function from the previous exercise to separate .c and .h files
//Create another function which calculates the circumference of a circle
//the radius of the circle should be passed as a parameter
//the function should return the calculated circumference
//circumference = 2 * radius * PI
//this function should be in the same .c and .h files as the one which calculates the area

int main()
{
    printf("The circumference of the square is: %f", calculate_circumference(3.14));
    return 0;
}
