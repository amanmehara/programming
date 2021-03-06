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

#ifndef MEHARA_SIEVE_OF_ERATOSTHENES_H_
#define MEHARA_SIEVE_OF_ERATOSTHENES_H_

#include <concepts>
#include <vector>

namespace mehara::mathematics {

template <typename T>
requires std::integral<T> 
std::vector<char> sieve_of_eratosthenes(T number)
{
    std::vector<char> is_prime(number + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (T i = 2; i * i <= number; i++) {
        if (is_prime[i]) {
            for (T j = i * 2; j <= number; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

} // namespace mehara::mathematics

#endif // MEHARA_SIEVE_OF_ERATOSTHENES_H_
