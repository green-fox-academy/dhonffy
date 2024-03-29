
#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`

    std::string abc[] = {"first", "second", "third"};

    std::swap(abc[0], abc[2]);

    std::cout << abc[0] << ", " << abc[1] << ", "<< abc[2] << std::endl;

    return 0;
}