// Copyright 2021 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MEHARA_TOTIENT_FUNCTION_H_
#define MEHARA_TOTIENT_FUNCTION_H_

#include <concepts>
#include <exception>
#include <vector>

namespace mehara::mathematics {

template <typename T>
requires std::integral<T> 
T phi_of(T number)
{
    T result = number;
    for (T i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            while (number % i == 0) {
                number /= i;
            }
            result -= result / i;
        }
    }
    if (number > 1) {
        result -= result / number;
    }
    return result;
}

/// Sieve of Eratosthenes
template <typename T>
requires std::integral<T> 
std::vector<T> phi_sieve(T number)
{
    std::vector<T> phi(number + 1);
    for (T i = 0; i <= number; i++) {
        phi[i] = i;
    }
    for (T i = 2; i <= number; i++) {
        if (phi[i] == i) {
            for (T j = i; j <= number; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

/// Divisor sum property (by Gauss)
template <typename T>
requires std::integral<T> 
std::vector<T> phi_divisor_sum(T number)
{
    std::vector<T> phi(number + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (T i = 2; i <= number; i++) {
        phi[i] = i - 1;
    }
    for (T i = 2; i <= number; i++) {
        for (T j = i * 2; j <= number; j += i) {
            phi[j] -= phi[i];
        }
    }
    return phi;
}

enum class phi_strategy { sieve, divisor_sum };

template <typename T>
requires std::integral<T> std::vector<T>
phi(T number, const phi_strategy& strategy = phi_strategy::sieve)
{
    switch (strategy) {
    case phi_strategy::sieve:
        return phi_sieve(number);
    case phi_strategy::divisor_sum:
        return phi_divisor_sum(number);
    default:
        throw std::exception();
    }
}

} // namespace mehara::mathematics

#endif // MEHARA_TOTIENT_FUNCTION_H_