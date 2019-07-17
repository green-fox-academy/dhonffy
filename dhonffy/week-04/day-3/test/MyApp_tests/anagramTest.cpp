#include <gtest/gtest.h>
#include "anagram.h"

TEST(anagram_check, test_anagram){
    std::string test1 = "greenfox";
    std::string test2 = "xofnnerg";
    ASSERT_EQ(testAnagram(test1, test2), 0);
}