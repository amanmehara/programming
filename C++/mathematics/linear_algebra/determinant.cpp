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

#include "determinant.h"

#include <cmath>
#include <iostream>
#include <vector>

namespace mehara::mathematics::linalg {

double compute_determinant(std::vector<std::vector<double>> matrix)
{
    const double epsilon = 1E-9;
    // All the dimensions of the square matrix are equal.
    int dimensions = matrix.size();
    double determinant = 1;
    for (int i = 0; i < dimensions; i++) {
        // Partial pivoting.
        int row = i;
        for (int j = i + 1; j < dimensions; j++) {
            if (abs(matrix[row][i]) < abs(matrix[j][i])) {
                row = j;
            }
        }
        if (row != i) {
            swap(matrix[row], matrix[i]);
            determinant *= -1;
        }
        if (abs(matrix[i][i]) < epsilon) {
            return 0;
        }
        determinant *= matrix[i][i];
        // Forward elimination.
        for (int j = i + 1; j < dimensions; j++) {
            auto multiplier = matrix[j][i] / matrix[i][i];
            if (abs(matrix[j][i]) > epsilon) {
                for (int k = i; k < dimensions; k++) {
                    matrix[j][k] -= multiplier * matrix[i][k];
                }
            }
        }
    }
    return determinant;
}

} // namespace mehara::mathematics::linalg
