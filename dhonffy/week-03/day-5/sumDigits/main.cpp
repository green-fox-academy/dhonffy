#include <iostream>

int sumDigits(unsigned int n);

int main()
{
    //    Write a recursive function that takes one parameter: n and adds numbers from 1 to n.
  std::cout <<sumDigits(123456789) << std::endl;
    return 0;
}

int sumDigits(unsigned int n)
{
    int sum = 0;
    if (n / 10 > 0) {
        sum = sum + n % 10 + sumDigits(n / 10);
    } else {
        return sum + n;
    }
}
