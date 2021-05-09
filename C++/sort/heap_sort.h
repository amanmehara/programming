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

#ifndef MEHARA_HEAP_SORT_H_
#define MEHARA_HEAP_SORT_H_

#include <algorithm>
#include <concepts>
#include <vector>

namespace mehara::sort {

template <typename T>
requires std::totally_ordered<T>
void sink(std::vector<T>& array, int index, int heap_size)
{
    while (2 * index + 1 < heap_size) {
        int child_index = 2 * index + 1;
        if (child_index < heap_size - 1 &&
            array[child_index] < array[child_index + 1]) {
            child_index++;
        }
        if (!(array[index] < array[child_index])) {
            break;
        }
        std::swap(array[index], array[child_index]);
        index = child_index;
    }
}

template <typename T>
requires std::totally_ordered<T>
void heap_sort(std::vector<T>& array)
{
    int _heap_size = array.size();
    for (int index = _heap_size / 2 - 1; index >= 0; index--) {
        sink(array, index, _heap_size);
    }
    while (_heap_size > 0) {
        std::swap(array[0], array[_heap_size - 1]);
        sink(array, 0, --_heap_size);
    }
}

} // namespace mehara::sort

#endif // MEHARA_HEAP_SORT_H_
