#include <iostream>

int numberAdder(unsigned int n);

int main()
{
    //    Write a recursive function that takes one parameter: n and adds numbers from 1 to n.
  std::cout <<numberAdder(1) << std::endl;
    return 0;
}

int numberAdder(unsigned int n)
{
    if (n == 0) {
        return 0;
    } else {
        return n + numberAdder(n - 1);
    }
}
