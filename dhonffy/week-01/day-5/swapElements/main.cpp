#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`
    std::string abc[] ={"first", "second", "third"};
    std::string tmp;
    tmp = abc[0];
    abc[0] = abc[2];
    abc[2] = tmp;
    return 0;
}