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

#include <string>

int integer_value(char symbol)
{
    switch (symbol) {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return -1;
    }
}

int roman_to_integer(const std::string& roman)
{
    int integer = 0;
    int successor = 0;
    for (int index = roman.size() - 1; index >= 0; index--) {
        auto current = integer_value(roman[index]);
        integer += current >= successor ? current : (-1 * current);
        successor = current;
    }
    return integer;
}