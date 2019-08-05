#include <stdio.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int storedNumber = 85;
    int guess;
    do {
        printf("Guess the stored number!\n");
        scanf("%d", &guess);
        storedNumber == guess ? printf("You found the number: %d\n", guess) :
        (storedNumber > guess ? printf("The stored number is higher.\n") : printf("The stored number is lower.\n"));
    } while (storedNumber != guess);
        return 0;
}