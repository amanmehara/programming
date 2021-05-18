#include "gtest/gtest.h"

#include "../mathematics/number_theory/binary_exponentiation.h"
#include "../mathematics/number_theory/factorization.h"
#include "../mathematics/number_theory/gcd.h"
#include "../mathematics/number_theory/lcm.h"
#include "../mathematics/number_theory/sieve_of_eratosthenes.h"

TEST(mathematics, binary_exponentiation)
{
    ASSERT_EQ(256, mehara::mathematics::binary_exponentiation_recursive(2, 8));
    ASSERT_EQ(243, mehara::mathematics::binary_exponentiation_recursive(3, 5));
    ASSERT_EQ(256, mehara::mathematics::binary_exponentiation_iterative(2, 8));
    ASSERT_EQ(243, mehara::mathematics::binary_exponentiation_iterative(3, 5));
}

TEST(mathematics, factorization_trial_division)
{
    auto actual_factors = mehara::mathematics::trial_division(20);
    std::vector<int> expected_factors{2, 2, 5};
    ASSERT_EQ(expected_factors.size(), actual_factors.size());
    for (int i = 0; i < actual_factors.size(); i++) {
        ASSERT_EQ(expected_factors[i], actual_factors[i]);
    }
}

TEST(mathematics, factorization_precomputed_primes)
{
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
    auto actual_factors = mehara::mathematics::factorize(221, primes);
    std::vector<int> expected_factors{13, 17};
    ASSERT_EQ(expected_factors.size(), actual_factors.size());
    for (int i = 0; i < actual_factors.size(); i++) {
        ASSERT_EQ(expected_factors[i], actual_factors[i]);
    }
}

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

TEST(mathematics, sieve_of_eratosthenes)
{
    auto is_prime = mehara::mathematics::sieve_of_eratosthenes(9);
    ASSERT_EQ(false, is_prime[0]);
    ASSERT_EQ(false, is_prime[1]);
    ASSERT_EQ(true, is_prime[2]);
    ASSERT_EQ(true, is_prime[3]);
    ASSERT_EQ(false, is_prime[4]);
    ASSERT_EQ(true, is_prime[5]);
    ASSERT_EQ(false, is_prime[6]);
    ASSERT_EQ(true, is_prime[7]);
    ASSERT_EQ(false, is_prime[8]);
    ASSERT_EQ(false, is_prime[9]);
}
