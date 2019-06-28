#include <iostream>
#include <string>

int sum(int par);

int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero
    // to the given parameter
    int parameter;
    std::cout << "Please, type a number!" << std::endl;
    std::cin >> parameter;
    std::cout << sum(parameter);
    return 0;
}

int sum(int par) {
    int sum = 0;
    for (int i = 1; i <= par; ++i) {
        sum = sum + i;
    }
    return sum;
}
