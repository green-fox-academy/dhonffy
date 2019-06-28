#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    int r[] = {54, 23, 66, 12};
    // - Print the sum of the second and the third element
    std::cout << r[2] + r[3] << std::endl;
    return 0;
}