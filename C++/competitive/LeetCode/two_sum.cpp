// Copyright 2018 Aman Mehara
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

#include <stdexcept>
#include <unordered_map>
#include <vector>

std::vector<int> two_sum(std::vector<int>& numbers, int target) {
    std::unordered_map<int, int> index_map;
    for (auto index = 0; index < numbers.size(); index++) {
        auto number = numbers[index];
        auto complement = target - number;
        if (index_map.count(complement) == 0) {
            index_map.insert({number, index});
        } else {
            return std::vector<int>{index_map.find(complement)->second, index};
        }
    }
    throw std::logic_error("No solution.");
}
