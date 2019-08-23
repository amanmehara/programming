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

#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

std::vector<int> top_k_frequent_elements(const std::vector<int>& numbers,
                                         int k) {
    std::unordered_map<int, int> frequency_map;
    for (const auto& number : numbers) {
        frequency_map[number]++;
    }

    auto _comp = [](const std::pair<int, int>& x,
                    const std::pair<int, int>& y) {
        return x.second > y.second;
    };
    std::priority_queue<int, std::vector<std::pair<int, int>>, decltype(_comp)>
        _priority_queue(_comp);

    for (const auto& _pair : frequency_map) {
        _priority_queue.push(_pair);
        if (_priority_queue.size() > k) {
            _priority_queue.pop();
        }
    }

    std::vector<int> frequent_elements(k);
    while (k > 0) {
        frequent_elements[--k] = _priority_queue.top().first;
        _priority_queue.pop();
    }
    return frequent_elements;
}
