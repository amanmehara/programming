// Copyright 2020 Aman Mehara
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

#include <algorithm>
#include <vector>

int maximum_area(const std::vector<int>& heights)
{
    int maximum_area_ = 0;
    int left_index = 0;
    int right_index = heights.size() - 1;
    while (left_index != right_index) {
        maximum_area_ = std::max(
            maximum_area_, std::min(heights[left_index], heights[right_index]) *
                               (right_index - left_index));
        if (heights[left_index] < heights[right_index]) {
            left_index++;
        }
        else {
            right_index--;
        }
    }
    return maximum_area_;
}
