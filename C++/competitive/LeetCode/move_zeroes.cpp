// Copyright 2019 Aman Mehara
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

#include <algorithm>
#include <vector>

void move_zeroes(std::vector<int>& numbers) {
    auto non_zero_index = 0;
    for (auto index = 0; index < numbers.size(); index++) {
        if (numbers[index] != 0) {
            std::swap(numbers[non_zero_index], numbers[index]);
            non_zero_index += 1;
        }
    }
}
