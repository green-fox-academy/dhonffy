#include <iostream>
#include <string>

void factorio(int input, double &factorial);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and
    //   overwrite its value.

    int input;
    double factorial = 1.0;
    std::cout << "Please, type a number!" << std::endl;
    std::cin >> input;
    factorio(input, factorial);
    std::cout << "Factorial: " << factorial << std::endl;
    return 0;
}

void factorio(int input, double &factorial) {

    for (int i = 1; i <= input; ++i) {
        factorial = factorial * static_cast<double> (i);
    }
}
