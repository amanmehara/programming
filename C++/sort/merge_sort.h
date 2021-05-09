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

#ifndef MEHARA_MERGE_SORT_H_
#define MEHARA_MERGE_SORT_H_

#include <concepts>
#include <iostream>
#include <limits>
#include <vector>

namespace mehara::sort {

template <typename T>
requires std::totally_ordered<T> 
void merge(std::vector<T>& array, std::vector<T>& auxiliary, int begin, 
           int middle, int end)
{
    for (auto i = begin, j = begin, k = middle + 1; i <= end; i++) {
        if (k > end || (j <= middle && auxiliary[j] <= auxiliary[k])) {
            array[i] = auxiliary[j++];
        }
        else {
            array[i] = auxiliary[k++];
        }
    }
}

template <typename T>
requires std::totally_ordered<T> 
void merge_sort(std::vector<T>& array, std::vector<T>& auxiliary, int begin, 
                int end)
{
    if (begin >= end) {
        return;
    }
    auto middle = begin + (end - begin) / 2;
    merge_sort(auxiliary, array, begin, middle);
    merge_sort(auxiliary, array, middle + 1, end);
    merge(array, auxiliary, begin, middle, end);
}

template <typename T>
requires std::totally_ordered<T> void merge_sort(std::vector<T>& array)
{
    std::vector<T> auxiliary(array.begin(), array.end());
    merge_sort(array, auxiliary, 0, array.size() - 1);
}

} // namespace mehara::sort

#endif // MEHARA_MERGE_SORT_H_
