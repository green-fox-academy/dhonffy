#include <stdio.h>
#include <stdlib.h>

int* read_integers(int);
void print_addresses(int*, int);
int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array
    int amount = 5;
    int* integers = read_integers(amount);
    print_addresses(integers, amount);
    return 0;
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

void print_addresses(int* integers, int length)
{
    for (int i = 0; i < length; ++i) {
        printf("Address %d: %p\n", i + 1, &(integers[i]));
    }
}