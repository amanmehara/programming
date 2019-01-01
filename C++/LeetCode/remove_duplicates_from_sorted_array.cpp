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

int remove_duplicates(std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    int unique_index = 0;
    for (int index = unique_index + 1; index < numbers.size(); index++) {
        if (numbers[unique_index] != numbers[index]) {
            unique_index++;
            numbers[unique_index] = numbers[index];
        }
    }
    return unique_index + 1;
}