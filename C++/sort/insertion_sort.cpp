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

#include "insertion_sort.h"

#include <vector>

namespace mehara::sort {

void insertion_sort(std::vector<double>& array) {

    for (size_t outer_idx = 2; outer_idx < array.size(); outer_idx++) {
        double key = array[outer_idx];
        size_t inner_idx = outer_idx - 1;
        while (inner_idx > 0 && array[inner_idx] > key) {
            array[inner_idx + 1] = array[inner_idx];
            inner_idx = inner_idx - 1;
        }
        array[inner_idx] = key;
    }
}

} // namespace mehara::sort
