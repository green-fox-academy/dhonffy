#include <stdio.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE* my_file = fopen("../my-file.txt", "r");
    if(my_file == NULL){
        printf("Error opening file!");
        return 1;
    }
    char read_line[256];
    while(fgets(read_line, 256, my_file)){
        printf("%s", read_line);
    }
    printf("\n");
    fclose(my_file);

    return 0;
}