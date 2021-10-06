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

#ifndef MEHARA_GCD_H_
#define MEHARA_GCD_H_

#include <concepts>

namespace mehara::mathematics {

/// Euclidean Algorithm
template <typename T>
requires std::integral<T> 
T gcd(T a, T b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/// Extended Euclidean ALgorithm
template <typename T>
requires std::integral<T> 
T gcd(T a, T b, T& x, T& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    auto d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

} // namespace mehara::mathematics

#endif // MEHARA_GCD_H_
