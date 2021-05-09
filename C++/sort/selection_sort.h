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

#ifndef MEHARA_SELECTION_SORT_H_
#define MEHARA_SELECTION_SORT_H_

#include <algorithm>
#include <concepts>
#include <vector>

namespace mehara::sort {

template <typename T>
requires std::totally_ordered<T>
void selection_sort(std::vector<T>& array)
{
    for (auto outer_index = 0; outer_index < array.size() - 1; outer_index++) {
        auto minimum_index = outer_index;
        for (auto inner_index = outer_index + 1; inner_index < array.size();
             inner_index++) {
            if (array[minimum_index] > array[inner_index]) {
                minimum_index = inner_index;
            }
        }
        if (minimum_index != outer_index) {
            std::swap(array[minimum_index], array[outer_index]);
        }
    }
}

} // namespace mehara::sort

#endif // MEHARA_SELECTION_SORT_H_
