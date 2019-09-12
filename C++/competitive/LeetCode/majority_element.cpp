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

#include <vector>

int majority_element(const std::vector<int>& numbers) {
    int _majority_element;
    int count = 0;
    for (const auto& number : numbers) {
        if (count == 0) {
            _majority_element = number;
        }
        count += (_majority_element == number) ? 1 : -1;
    }
    return _majority_element;
}