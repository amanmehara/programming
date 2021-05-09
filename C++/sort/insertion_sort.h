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

#ifndef MEHARA_INSERTON_SORT_H_
#define MEHARA_INSERTON_SORT_H_

#include <concepts>
#include <vector>

namespace mehara::sort {

template <typename T>
requires std::totally_ordered<T>
void insertion_sort(std::vector<T>& array)
{
    for (auto outer_index = 1; outer_index < array.size(); outer_index++) {
        auto key = array[outer_index];
        auto inner_index = outer_index - 1;
        while (inner_index >= 0 && array[inner_index] > key) {
            array[inner_index + 1] = array[inner_index];
            inner_index = inner_index - 1;
        }
        array[inner_index + 1] = key;
    }
}

} // namespace mehara::sort

#endif // MEHARA_INSERTON_SORT_H_
