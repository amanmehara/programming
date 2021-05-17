#include "gtest/gtest.h"

#include "../mathematics/number_theory/gcd.h"
#include "../mathematics/number_theory/lcm.h"

TEST(mathematics, gcd)
{
    ASSERT_EQ(1, mehara::mathematics::gcd(71, 23));
    ASSERT_EQ(1, mehara::mathematics::gcd(23, 71));
    ASSERT_EQ(1, mehara::mathematics::gcd(37, 29));
    ASSERT_EQ(4, mehara::mathematics::gcd(20, 16));
    ASSERT_EQ(4, mehara::mathematics::gcd(16, 20));
    ASSERT_EQ(9, mehara::mathematics::gcd(90, 27));
}

TEST(mathematics, lcm)
{
    ASSERT_EQ(1633, mehara::mathematics::lcm(71, 23));
    ASSERT_EQ(1633, mehara::mathematics::lcm(23, 71));
    ASSERT_EQ(1073, mehara::mathematics::lcm(37, 29));
    ASSERT_EQ(80, mehara::mathematics::lcm(20, 16));
    ASSERT_EQ(80, mehara::mathematics::lcm(16, 20));
    ASSERT_EQ(270, mehara::mathematics::lcm(90, 27));
}