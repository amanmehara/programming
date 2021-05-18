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

#ifndef MEHARA_FACTORIZATION_H_
#define MEHARA_FACTORIZATION_H_

#include <concepts>
#include <vector>

namespace mehara::mathematics {

template <typename T>
requires std::integral<T> 
std::vector<T> trial_division(T number)
{
    std::vector<T> factorization;
    for (T divisor = 2; divisor * divisor <= number; divisor++) {
        while (number % divisor == 0) {
            factorization.push_back(divisor);
            number /= divisor;
        }
    }
    if (number > 1) {
        factorization.push_back(number);
    }
    return factorization;
}

template <typename T>
requires std::integral<T> std::vector<T> 
factorize(T number, const std::vector<T>& primes)
{
    std::vector<T> factorization;
    for (const auto& divisor : primes) {
        if (divisor * divisor > number) {
            break;
        }
        while (number % divisor == 0) {
            factorization.push_back(divisor);
            number /= divisor;
        }
    }
    if (number > 1) {
        factorization.push_back(number);
    }
    return factorization;
}

} // namespace mehara::mathematics

#endif // MEHARA_FACTORIZATION_H_
