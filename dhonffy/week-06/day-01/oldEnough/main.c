#include <stdio.h>
#include <stdlib.h>
#include "oldEnough.h"
int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary
    int age;
    printf("How old are you?\n");
    scanf("%d", &age);
    if (oldEnough(age) == 0){
        printf("You're not old enough to buy alcohol.");
    } else {
        printf("You're old enough to buy alcohol.");
    }
    return 0;
}

int oldEnough(int age)
{
    return age >= 18 ? 1 : 0;
}