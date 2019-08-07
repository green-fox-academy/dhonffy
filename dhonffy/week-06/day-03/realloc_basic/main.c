#include <stdio.h>
#include <stdlib.h>


// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int x;
    printf("Please enter a number!\n");
    scanf("%d", &x);
    int *array_x = malloc(x * sizeof(int));
    printf("Please enter %d numbers!\n", x);
    for (int i = 0; i < x; ++i) {
        scanf("%d", &array_x[i]);
    }
    int y = 0;
    for (int i = 0; i < x; ++i) {
        y += array_x[i];
    }
    realloc(array_x, y * sizeof(int));
    for (int i = 1; i <= y; ++i) {
        array_x[i] = i;
    }
    for (int i = 1; i <= y; ++i) {
        printf("%d", array_x[i]);
        if (i != y) {
            printf(", ");
        }
        if (i % 10 == 0 && i != y){
            printf("\n");
        }
    }
    return 0;
}