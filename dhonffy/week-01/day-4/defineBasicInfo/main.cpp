#include <iostream>

int main(int argc, char* args[]) {

    // Define several things as a variable then print their values
    // Your name as a string
    std::string name = "Daniel Honffy";
    std::cout << "My name is " << name << std::endl;
    // Your age as an integer
    int age = 34;
    std::cout << "I am " << age << " years old." << std::endl;
    // Your height in meters as a double
    double height = 1.71;
    std::cout << "I am " << height << " meters tall." << std::endl;
    // Whether you are married or not as a boolean
    bool married = false;
    std::cout << "Marriage: " << married << std::endl;

    return 0;
}