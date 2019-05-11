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

#include "merge_sort.h"

#include <limits>
#include <vector>

namespace mehara::sort {

void merge(std::vector<double>& array, int begin, int middle, int end) {

    auto left_size = middle - begin + 1;
    std::vector<double> left(left_size + 1);
    auto left_index = 0;
    while (left_index < left.size() - 1) {
        left[left_index] = array[begin + left_index];
        left_index++;
    }
    left[left_index] = std::numeric_limits<double>::max();

    auto right_size = end - middle;
    std::vector<double> right(right_size + 1);
    auto right_index = 0;
    while (right_index < right.size() - 1) {
        right[right_index] = array[middle + right_index + 1];
        right_index++;
    }
    right[right_index] = std::numeric_limits<double>::max();

    left_index = 0;
    right_index = 0;
    for (auto index = begin; index <= end; index++) {
        if (left[left_index] <= right[right_index]) {
            array[index] = left[left_index];
            left_index++;
        } else {
            array[index] = right[right_index];
            right_index++;
        }
    }
}

void merge_sort(std::vector<double>& array, int begin, int end) {
    if (begin < end) {
        auto middle = begin + (end - begin) / 2.0;

        merge_sort(array, begin, middle);
        merge_sort(array, middle + 1, end);

        merge(array, begin, middle, end);
    }
}

void merge_sort(std::vector<double>& array) {
    auto begin = 0;
    auto end = array.size() - 1;

    merge_sort(array, begin, end);
}

} // namespace mehara::sort
