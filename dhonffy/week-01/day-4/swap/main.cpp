
#include <iostream>

int main(int argc, char* args[]) {

    // Swap the values of the variables
    int a = 123;
    int b = 526;
    int swap;
    swap = a;
    a = b;
    b = swap;
    std::cout <<"a is: " << a << std::endl;
    std::cout <<"b is: " << b << std::endl;

    return 0;
}