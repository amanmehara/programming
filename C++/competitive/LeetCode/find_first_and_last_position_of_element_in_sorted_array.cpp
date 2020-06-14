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

#include <vector>

int lower_bound(const std::vector<int>& numbers, int target)
{
    int index = 0;
    int count = numbers.size();
    while (count > 0) {
        auto step = count / 2;
        if (numbers[index + step] < target) {
            index += step + 1;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return index;
}

int upper_bound(const std::vector<int>& numbers, int target)
{
    int index = 0;
    int count = numbers.size();
    while (count > 0) {
        auto step = count / 2;
        if (!(target < numbers[index + step])) {
            index += (step + 1);
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return index;
}

std::vector<int> search_range(const std::vector<int>& numbers, int target)
{
    auto first = lower_bound(numbers, target);
    if (first == numbers.size() || numbers[first] != target) {
        return {-1, -1};
    }
    auto last = upper_bound(numbers, target);
    return {first, last - 1};
}