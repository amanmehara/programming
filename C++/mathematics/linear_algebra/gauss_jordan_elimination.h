// Copyright 2021 Aman Mehara
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

#ifndef MEHARA_GAUSS_JORDAN_ELIMINATION_H_
#define MEHARA_GAUSS_JORDAN_ELIMINATION_H_

#include <vector>

namespace mehara::mathematics::linalg {

int gauss_jordan_elimination(std::vector<std::vector<double>> augmented_matrix,
                             std::vector<double>& solution);

} // namespace mehara::mathematics::linalg

#endif // MEHARA_GAUSS_JORDAN_ELIMINATION_H_
