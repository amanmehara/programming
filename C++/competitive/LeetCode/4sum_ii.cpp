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

#include <unordered_map>
#include <vector>

int four_sum_count(const std::vector<int>& A, const std::vector<int>& B,
                   const std::vector<int>& C, const std::vector<int>& D) {

    std::unordered_map<int, int> frequency;
    for (const auto& _a : A) {
        for (const auto& _b : B) {
            frequency[_a + _b]++;
        }
    }
    auto _tuples = 0;
    for (const auto& _c : C) {
        for (const auto& _d : D) {
            auto it = frequency.find(-(_c + _d));
            if (it != frequency.end()) {
                _tuples += it->second;
            }
        }
    }

    return _tuples;
}