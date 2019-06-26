#include <iostream>

int main(int argc, char const *argv[]) {

    // Positive, negative and zero
    std::cout << 42 << std::endl;
    std::cout << 0 << std::endl;
    std::cout << -3 << std::endl;

    int maxVal=2147483647;
    int minVal=-2147483648;
    int diff=2147483648;
    //Maximum value 2 147 483 647
    std::cout << maxVal << std::endl;
    //Minimum value -2 147 483 648
    std::cout << minVal << std::endl;

    // What will be the output for this and why?
    std::cout << diff << std::endl;
    return 0;
}