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

#include <algorithm>
#include <stdexcept>
#include <vector>

void sort_colors(std::vector<int>& colors) {

    auto zero_index = 0;
    auto one_index = 0;
    int two_index = colors.size() - 1;

    while (one_index <= two_index) {
        switch (colors[one_index]) {
        case 0:
            std::swap(colors[zero_index], colors[one_index]);
            zero_index++;
            one_index++;
            break;
        case 1:
            one_index++;
            break;
        case 2:
            std::swap(colors[two_index], colors[one_index]);
            two_index--;
            break;
        default:
            throw std::invalid_argument("Unknown color.");
        }
    }
}