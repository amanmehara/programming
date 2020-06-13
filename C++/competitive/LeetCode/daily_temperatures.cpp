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

#include <stack>
#include <vector>

std::vector<int> daily_temperatures(const std::vector<int>& temperatures)
{
    std::vector<int> wait(temperatures.size());
    std::stack<int> _stack;
    for (int i = temperatures.size() - 1; i >= 0; i--) {
        while (!_stack.empty() &&
               temperatures[i] >= temperatures[_stack.top()]) {
            _stack.pop();
        }
        wait[i] = _stack.empty() ? 0 : _stack.top() - i;
        _stack.push(i);
    }
    return wait;
}