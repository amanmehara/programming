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

#include <algorithm>
#include <vector>

namespace mehara::sort {

int partition(std::vector<double>& array, int begin, int end) {
    auto pivot = array[end];
    auto i = begin;
    for (auto j = i; j < end; j++) {
        if (array[j] < pivot) {
            std::swap(array[i], array[j]);
            i += 1;
        }
    }
    std::swap(array[i], array[end]);
    return i;
}

void quick_sort(std::vector<double>& array, int begin, int end) {
    if (begin <= end) {
        auto _partition = partition(array, begin, end);
        quick_sort(array, begin, _partition - 1);
        quick_sort(array, _partition + 1, end);
    }
}

void quick_sort(std::vector<double>& array) {
    auto begin = 0;
    auto end = array.size() - 1;

    quick_sort(array, begin, end);
}

} // namespace mehara::sort
