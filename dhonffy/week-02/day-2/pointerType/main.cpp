#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of
    // that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";
    int *aPtr = &a;
    double *bPtr = &b;
    std::string *namePtr = &name;
    std::cout << "address a: " << &a << std::endl;
    std::cout << "address b: " << &b << std::endl;
    std::cout << "address name: " << &name << std::endl;
    std::cout << "value od pointer a: " << aPtr << std::endl;
    std::cout << "value od pointer b: " << bPtr << std::endl;
    std::cout << "value od pointer name: " << namePtr << std::endl;

    return 0;
}