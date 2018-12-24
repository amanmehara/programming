// Copyright 2018 Aman Mehara
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

void merge(std::vector<int>& array_1, int size_1, std::vector<int>& array_2,
           int size_2) {
    int index = size_1 + size_2 - 1;
    int index_1 = size_1 - 1;
    int index_2 = size_2 - 1;

    while (index_1 >= 0 && index_2 >= 0) {
        array_1[index--] = (array_1[index_1] >= array_2[index_2])
                               ? array_1[index_1--]
                               : array_2[index_2--];
    }

    while (index_1 >= 0) {
        array_1[index--] = array_1[index_1--];
    }

    while (index_2 >= 0) {
        array_1[index--] = array_2[index_2--];
    }
}