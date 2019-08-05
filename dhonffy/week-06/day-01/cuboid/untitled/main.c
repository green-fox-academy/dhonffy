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

    printf("Please type the first side of the cuboid!\n");
    scanf("%d", &a);
    //printf("a: %d\n", a);
    printf("Please type the second side of the cuboid!\n");
    scanf("%d", &b);
    //printf("b: %d\n", b);
    printf("Please type the third side of the cuboid!\n");
    scanf("%d", &c);
    //printf("c: %d\n",c);

    int surface = 2 * (a * b + b * c + a * c);
    int volume = a * b * c;

    printf("Surface area: %d.\n", surface);
    printf("Volume: %d.\n", volume);
    return 0;
}