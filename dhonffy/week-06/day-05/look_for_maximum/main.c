#include <stdio.h>
#include <stdlib.h>
#include "read_size.h"

int* read_integers(int);
int find_maximum(int*, int);
int* find_maximum_address(int*, int);

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it
    int amount = read_size();
    int* integers = read_integers(amount);
    printf("The maximum is: %d, the address of it is: %p", find_maximum(integers, amount), find_maximum_address(integers, amount));
    free(integers);
    return 0;
}

int find_maximum(int* integers, int length)
{
    int maximum = 0x80000000;
    for (int i = 0; i < length; ++i) {
        if (integers[i] > maximum){
            maximum = integers[i];
        }
    }
    return maximum;
}

int* find_maximum_address(int* integers, int length)
{
    int maximum = 0x80000000;
    int* maximum_value;
    for (int i = 0; i < length; ++i) {
        if (integers[i] > maximum){
            maximum = integers[i];
            maximum_value = &integers[i];
        }
    }
    return maximum_value;
}

int* read_integers(int amount)
{
    int* integers = (int*) malloc(amount * sizeof(int));
    for (int i = 0; i < amount; ++i) {
        printf("Type the %d. number!\n", i + 1);
        scanf("%d", &integers[i]);
    }
    return integers;
}

