#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "findAppearence.h"
int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char find_it_in_me[10];
    char find_me_there;
    printf("Type a string!\n");
    scanf("%s", find_it_in_me);
    printf("Type a character!\n");
    scanf(" %c", &find_me_there);
    printf("%d", find_appearence(find_it_in_me, find_me_there));
    return 0;
}

int find_appearence(char* find_it_in_me, char find_me_there)
{
    int p = 0;
    while (find_it_in_me[p] != '\0'){
        if (find_it_in_me[p] == find_me_there){
            return p;
        }
        ++p;
    }
    return -1;
}
