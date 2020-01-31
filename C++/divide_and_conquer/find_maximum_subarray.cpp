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

#include <limits>
#include <tuple>
#include <vector>

auto find_maximum_crossing_subarray(const std::vector<int>& _array, int low,
                                    int mid, int high)
{
    int sum;
    auto max_left = mid;
    auto left_sum = std::numeric_limits<int>::min();
    sum = 0;
    for (int index = mid; index >= low; index--) {
        sum += _array[index];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = index;
        }
    }

    sum = 0;
    auto max_right = mid + 1;
    auto right_sum = std::numeric_limits<int>::min();
    for (int index = mid + 1; index <= high; index++) {
        sum += _array[index];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = index;
        }
    }

    return std::make_tuple<>(max_left, max_right, left_sum + right_sum);
}

auto find_maximum_subarray(const std::vector<int>& _array, int low, int high)
{
    if (low == high) {
        return std::make_tuple<>(low, high, _array[low]);
    }
    else {
        auto mid = (low + high) / 2;
        auto [left_low, left_high, left_sum] =
            find_maximum_subarray(_array, low, mid);
        auto [right_low, right_high, right_sum] =
            find_maximum_subarray(_array, mid + 1, high);
        auto [cross_low, cross_high, cross_sum] =
            find_maximum_crossing_subarray(_array, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            return std::make_tuple<>(left_low, left_high, left_sum);
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum) {
            return std::make_tuple<>(right_low, right_high, right_sum);
        }
        else {
            return std::make_tuple<>(cross_low, cross_high, cross_sum);
        }
    }
}

auto find_maximum_subarray(const std::vector<int>& _array)
{
    return find_maximum_subarray(_array, 0, _array.size() - 1);
}
