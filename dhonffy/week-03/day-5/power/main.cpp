#include <iostream>

int power(unsigned int n, unsigned int powerN);

int main()
{
    //   Given base and n that are both 1 or more, compute recursively (no loops) the
    //   value of base to the n power, so powerN(3, 2) is 9 (3 squared).
    std::cout << power(10, 3) << std::endl;
    return 0;
}

int power(unsigned int n, unsigned int powerN)
{
    int mul = 0;
    if (powerN > 1) {
        mul = n * power(n, powerN - 1);
    } else {
        mul = n;
    }
    return mul;
}
