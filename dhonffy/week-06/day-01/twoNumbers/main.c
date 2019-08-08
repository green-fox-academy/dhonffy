#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    int addition = 13 + 22;

    printf("13 + 22 = %d\n", addition);

    // Print the result of 13 substracted from 22

    int subtraction = 22-13;

    printf("22 - 13 = %d\n", subtraction);

    // Print the result of 22 multiplied by 13

    int multiplication = 13 * 22;

    printf("13 * 22 = %d\n", multiplication);

    // Print the result of 22 divided by 13 (as a decimal fraction)

    float division = 22.0 / 13.0;

    printf("22 / 13 = %f\n", division);

    // Print the reminder of 22 divided by 13

    int modulo = 22 % 13;

    printf("22 %% 13 = %d\n", modulo);

    // Store the results in variables and use them when you display the result

    return 0;
}