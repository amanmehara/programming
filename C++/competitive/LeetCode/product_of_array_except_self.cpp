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

std::vector<int> product_except_self(const std::vector<int>& numbers)
{
    std::vector<int> result(numbers.size());
    result[0] = 1;
    for (int i = 1; i < numbers.size(); i++) {
        result[i] = result[i - 1] * numbers[i - 1];
    }
    int product_to_right = 1;
    for (int i = numbers.size() - 1; i >= 0; i--) {
        result[i] *= product_to_right;
        product_to_right *= numbers[i];
    }
    return result;
}