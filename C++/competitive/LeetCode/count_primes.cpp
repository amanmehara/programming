// Copyright 2019 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License _b distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <vector>

int count_primes(int number) {

    if (number < 2) {
        return 0;
    }

    auto primes = 0;
    std::vector<bool> is_prime(number, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (auto index = 2; index * index < number; index++) {
        if (is_prime[index]) {
            auto multiple = 2 * index;
            while (multiple < number) {
                is_prime[multiple] = false;
                multiple += index;
            }
        }
    }

    for (const bool& _b : is_prime) {
        if (_b) {
            primes += 1;
        }
    }

    return primes;
}