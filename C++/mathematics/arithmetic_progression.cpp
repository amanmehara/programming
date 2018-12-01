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

#include "arithmetic_progression.h"

#include <stdexcept>
#include <vector>

std::vector<double> arithmetic_progression(
    double first_term, double common_difference, int terms) {
    if (terms < 1) {
        throw std::domain_error("terms < 1");
    }

    std::vector<double> progression;
    for (int term_index = 0; term_index < terms; term_index++) {
        progression.push_back(first_term + common_difference * term_index);
    }

    return progression;
}