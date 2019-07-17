#include <gtest/gtest.h>
#include "sum.h"
#include <vector>

TEST(sum_check, test_sum){
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(59);
    numbers.push_back(6);
    numbers.push_back(8);
    numbers.push_back(-100);
    ASSERT_EQ(getSum(numbers), -16);
}