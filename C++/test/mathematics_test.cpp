#include "gtest/gtest.h"

#include "../mathematics/number_theory/binary_exponentiation.h"
#include "../mathematics/number_theory/factorization.h"
#include "../mathematics/number_theory/gcd.h"
#include "../mathematics/number_theory/lcm.h"
#include "../mathematics/number_theory/sieve_of_eratosthenes.h"
#include "../mathematics/number_theory/totient_function.h"

namespace mehara::mathematics::test {

TEST(mathematics, binary_exponentiation)
{
    ASSERT_EQ(256, binary_exponentiation_recursive(2, 8));
    ASSERT_EQ(243, binary_exponentiation_recursive(3, 5));
    ASSERT_EQ(256, binary_exponentiation_iterative(2, 8));
    ASSERT_EQ(243, binary_exponentiation_iterative(3, 5));
}

TEST(mathematics, factorization_trial_division)
{
    auto actual_factors = trial_division(20);
    std::vector<int> expected_factors{2, 2, 5};
    ASSERT_EQ(expected_factors.size(), actual_factors.size());
    for (int i = 0; i < actual_factors.size(); i++) {
        ASSERT_EQ(expected_factors[i], actual_factors[i]);
    }
}

TEST(mathematics, factorization_precomputed_primes)
{
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
    auto actual_factors = factorize(221, primes);
    std::vector<int> expected_factors{13, 17};
    ASSERT_EQ(expected_factors.size(), actual_factors.size());
    for (int i = 0; i < actual_factors.size(); i++) {
        ASSERT_EQ(expected_factors[i], actual_factors[i]);
    }
}

TEST(mathematics, gcd_euclidean_algorithm)
{
    ASSERT_EQ(1, gcd(71, 23));
    ASSERT_EQ(1, gcd(23, 71));
    ASSERT_EQ(1, gcd(37, 29));
    ASSERT_EQ(4, gcd(20, 16));
    ASSERT_EQ(4, gcd(16, 20));
    ASSERT_EQ(9, gcd(90, 27));
}

TEST(mathematics, gcd_extended_euclidean_algorithm)
{
    int x, y;
    ASSERT_EQ(1, gcd(71, 23, x, y));
    ASSERT_EQ(-11, x);
    ASSERT_EQ(34, y);
    ASSERT_EQ(1, gcd(23, 71, x, y));
    ASSERT_EQ(34, x);
    ASSERT_EQ(-11, y);
    ASSERT_EQ(1, gcd(37, 29, x, y));
    ASSERT_EQ(11, x);
    ASSERT_EQ(-14, y);
    ASSERT_EQ(4, gcd(20, 16, x, y));
    ASSERT_EQ(1, x);
    ASSERT_EQ(-1, y);
    ASSERT_EQ(4, gcd(16, 20, x, y));
    ASSERT_EQ(-1, x);
    ASSERT_EQ(1, y);
    ASSERT_EQ(9, gcd(90, 27, x, y));
    ASSERT_EQ(1, x);
    ASSERT_EQ(-3, y);
}

TEST(mathematics, lcm)
{
    ASSERT_EQ(1633, lcm(71, 23));
    ASSERT_EQ(1633, lcm(23, 71));
    ASSERT_EQ(1073, lcm(37, 29));
    ASSERT_EQ(80, lcm(20, 16));
    ASSERT_EQ(80, lcm(16, 20));
    ASSERT_EQ(270, lcm(90, 27));
}

TEST(mathematics, sieve_of_eratosthenes)
{
    auto is_prime = sieve_of_eratosthenes(9);
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

TEST(mathematics, totient_function_phi)
{
    std::vector<int> expected_values{0, 1, 1, 2, 2, 4, 2, 6, 4, 6};
    ASSERT_EQ(expected_values[1], phi_of(1));
    ASSERT_EQ(expected_values[3], phi_of(3));
    ASSERT_EQ(expected_values[4], phi_of(4));
    ASSERT_EQ(expected_values[5], phi_of(5));
    ASSERT_EQ(expected_values[7], phi_of(7));
    auto actual_values_1 = phi(8, phi_strategy::sieve);
    ASSERT_GE(expected_values.size(), actual_values_1.size());
    for (int i = 0; i < actual_values_1.size(); i++) {
        ASSERT_EQ(expected_values[i], actual_values_1[i]);
    }
    auto actual_values_2 = phi(6, phi_strategy::divisor_sum);
    ASSERT_GE(expected_values.size(), actual_values_2.size());
    for (int i = 0; i < actual_values_2.size(); i++) {
        ASSERT_EQ(expected_values[i], actual_values_2[i]);
    }
}

} // namespace mehara::mathematics::test
