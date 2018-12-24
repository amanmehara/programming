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

#include <stack>
#include <string>

bool is_valid(const std::string& parentheses) {
    std::stack<char> parenthesis_stack;
    for (const auto& parenthesis : parentheses) {
        if (parenthesis == '(' || parenthesis == '{' || parenthesis == '[') {
            parenthesis_stack.push(parenthesis);
        } else {
            if (parenthesis_stack.empty() ||
                (parenthesis_stack.top() != '(' && parenthesis == ')') ||
                (parenthesis_stack.top() != '{' && parenthesis == '}') ||
                (parenthesis_stack.top() != '[' && parenthesis == ']')) {
                return false;
            }
            parenthesis_stack.pop();
        }
    }
    return parenthesis_stack.empty();
}