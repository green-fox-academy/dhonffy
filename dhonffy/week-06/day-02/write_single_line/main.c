#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE* my_file = fopen("../my-file.txt", "r");
    if(my_file == NULL){
        printf("Error opening file!");
        return 1;
    }
    unsigned char buffer[10];
    strcpy(buffer, "Dani");
    int i;
    for(i = 0; i < 4; i++) {
        fputc(buffer[i], my_file);
    }
    fclose(my_file);

    return 0;
}