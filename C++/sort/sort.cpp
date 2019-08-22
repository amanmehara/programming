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

#include "sort.h"

#include <exception>
#include <vector>

#include "bubble_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

namespace mehara::sort {

void sort(std::vector<double>& array, strategy strategy) {
    switch (strategy) {
    case strategy::bubble_sort:
        bubble_sort(array);
        break;
    case strategy::heap_sort:
        heap_sort(array);
        break;
    case strategy::insertion_sort:
        insertion_sort(array);
        break;
    case strategy::merge_sort:
        merge_sort(array);
        break;
    case strategy::quick_sort:
        quick_sort(array);
        break;
    case strategy::selection_sort:
        selection_sort(array);
        break;
    default:
        throw std::exception();
    }
}

} // namespace mehara::sort
