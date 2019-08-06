#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer;
    computer.cpu_speed_GHz = 1.2;
    computer.ram_size_GB = 8;
    computer.bits = 64;

    printf("computer CPU speed %f GHz, RAM size %d GB, %d bits\n", computer.cpu_speed_GHz, computer.ram_size_GB,
                                                                                         computer.bits);

    Notebook notebook;
    notebook.cpu_speed_GHz = 2.1;
    notebook.ram_size_GB = 16;
    notebook.bits = 32;

    printf("notebook CPU speed %f GHz, RAM size %d GB, %d bits\n", notebook.cpu_speed_GHz, notebook.ram_size_GB,
                                                                                         notebook.bits);

    return 0;
}