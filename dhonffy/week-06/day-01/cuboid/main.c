#include<stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    int a;
    int b;
    int c;
    printf("Please add the first side of the cuboid!\n");
    scanf("%d", &a);
    printf("Please add the second side of the cuboid!\n");
    scanf("%d", &b);
    printf("Please add the third side of the cuboid!\n");
    scanf("%d", &c);
    int surface = 2 * (a * b + b * c + a * c);
    int volume = a * b * c;
    printf("Surface: %d\n", surface);
    printf("Volume: %d\n", volume);

    return 0;
}