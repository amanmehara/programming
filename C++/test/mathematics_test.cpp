#include "gtest/gtest.h"

#include "../mathematics/number_theory/factorization.h"
#include "../mathematics/number_theory/gcd.h"
#include "../mathematics/number_theory/lcm.h"

TEST(mathematics, factorization_trial_division) {
  auto actual_factors = mehara::mathematics::trial_division(20);
  std::vector<int> expected_factors{2, 2, 5};
  ASSERT_EQ(expected_factors.size(), actual_factors.size());
  for (int i = 0; i < actual_factors.size(); i++) {
    ASSERT_EQ(expected_factors[i], actual_factors[i]);
  }
}

TEST(mathematics, factorization_precomputed_primes) {
  std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
  auto actual_factors = mehara::mathematics::factorize(221, primes);
  std::vector<int> expected_factors{13, 17};
  ASSERT_EQ(expected_factors.size(), actual_factors.size());
  for (int i = 0; i < actual_factors.size(); i++) {
    ASSERT_EQ(expected_factors[i], actual_factors[i]);
  }
}

TEST(mathematics, gcd) {
  ASSERT_EQ(1, mehara::mathematics::gcd(71, 23));
  ASSERT_EQ(1, mehara::mathematics::gcd(23, 71));
  ASSERT_EQ(1, mehara::mathematics::gcd(37, 29));
  ASSERT_EQ(4, mehara::mathematics::gcd(20, 16));
  ASSERT_EQ(4, mehara::mathematics::gcd(16, 20));
  ASSERT_EQ(9, mehara::mathematics::gcd(90, 27));
}

TEST(mathematics, lcm) {
  ASSERT_EQ(1633, mehara::mathematics::lcm(71, 23));
  ASSERT_EQ(1633, mehara::mathematics::lcm(23, 71));
  ASSERT_EQ(1073, mehara::mathematics::lcm(37, 29));
  ASSERT_EQ(80, mehara::mathematics::lcm(20, 16));
  ASSERT_EQ(80, mehara::mathematics::lcm(16, 20));
  ASSERT_EQ(270, mehara::mathematics::lcm(90, 27));
}
