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

#include <string>
#include <vector>

std::vector<std::string> fizz_buzz(int n) {
    std::vector<std::string> fizz_buzz;
    for (auto i = 1; i <= n; i++) {
        std::string str;

        if (i % 3 == 0) {
            str += "Fizz";
        }
        if (i % 5 == 0) {
            str += "Buzz";
        }

        if (str.empty()) {
            fizz_buzz.push_back(std::to_string(i));
        } else {
            fizz_buzz.push_back(str);
        }
    }
    return fizz_buzz;
}