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

#include <utility>
#include <vector>

void permute(std::vector<int>& numbers, int begin,
             std::vector<std::vector<int>>& permutations)
{
    if (begin >= numbers.size()) {
        permutations.push_back(numbers);
    }
    else {
        for (auto i = begin; i < numbers.size(); i++) {
            std::swap(numbers[begin], numbers[i]);
            permute(numbers, begin + 1, permutations);
            std::swap(numbers[begin], numbers[i]);
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& numbers)
{
    std::vector<std::vector<int>> permutations;
    permute(numbers, 0, permutations);
    return permutations;
}
