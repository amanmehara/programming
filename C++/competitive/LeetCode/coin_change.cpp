// Copyright 2020 Aman Mehara
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

#include <climits>
#include <vector>

int coin_change(const std::vector<int>& coins, int remaining,
                std::vector<int>& count)
{
    if (remaining < 0) {
        return -1;
    }
    if (remaining == 0) {
        return 0;
    }
    if (count[remaining - 1] != INT_MAX) {
        return count[remaining - 1];
    }
    int minimum = INT_MAX;
    for (const auto& coin : coins) {
        auto result = coin_change(coins, remaining - coin, count);
        if (result >= 0 && result < minimum) {
            minimum = result + 1;
        }
    }
    count[remaining - 1] = (minimum == INT_MAX) ? -1 : minimum;
    return count[remaining - 1];
}

int coin_change(const std::vector<int>& coins, int amount)
{
    if (amount == 0) {
        return 0;
    }
    std::vector<int> count(amount, INT_MAX);
    return coin_change(coins, amount, count);
}