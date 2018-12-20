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
#include <vector>

int evaluate_reverse_polish_notation(std::vector<std::string>& tokens) {
    std::stack<int> operand_stack;
    for (const auto& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int second_operand = operand_stack.top();
            operand_stack.pop();
            int first_operand = operand_stack.top();
            operand_stack.pop();
            if (token == "+") {
                operand_stack.push(first_operand + second_operand);
            } else if (token == "-") {
                operand_stack.push(first_operand - second_operand);
            } else if (token == "*") {
                operand_stack.push(first_operand * second_operand);
            } else {
                operand_stack.push(first_operand / second_operand);
            }
        } else {
            operand_stack.push(std::stoi(token));
        }
    }
    return operand_stack.top();
}