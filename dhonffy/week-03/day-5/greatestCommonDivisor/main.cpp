#include <iostream>
#include <vector>
unsigned int greatestCommonDivisore(unsigned int a, unsigned int b);
int main()
{
    //   Find the greatest common divisor of two numbers using recursion.
    std::cout << greatestCommonDivisore(20, 25) << std::endl;
    return 0;
}

unsigned int greatestCommonDivisore(unsigned int a, unsigned int b)
{
    if (b==0)
        return a;
    else
        return greatestCommonDivisore(b, a % b);
}
