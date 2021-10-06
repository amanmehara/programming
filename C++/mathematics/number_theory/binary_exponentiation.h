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

#ifndef MEHARA_BINARY_EXPONENTIATION_H_
#define MEHARA_BINARY_EXPONENTIATION_H_

#include <concepts>
#include <vector>

namespace mehara::mathematics {

template <typename T>
requires std::integral<T> 
T binary_exponentiation_recursive(T a, T b)
{
    if (b == 0) {
        return 1;
    }
    auto power = binary_exponentiation_recursive(a, b / 2);
    return (b & 1) ? power * power * a : power * power;
}

template <typename T>
requires std::integral<T> 
T binary_exponentiation_iterative(T a, T b)
{
    T power = 1;
    while (b > 0) {
        if (b & 1) {
            power *= a;
        }
        a *= a;
        b >>= 1;
    }
    return power;
}

} // namespace mehara::mathematics

#endif // MEHARA_BINARY_EXPONENTIATION_H_
