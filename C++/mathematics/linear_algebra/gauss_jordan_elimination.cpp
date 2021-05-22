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

#include "gauss_jordan_elimination.h"

#include <cmath>
#include <unordered_map>
#include <vector>

namespace mehara::mathematics::linalg {

const double epsilon = 1E-9;

bool is_solution(const std::vector<std::vector<double>>& augmented_matrix,
                 const std::vector<double>& solution)
{
    int m = augmented_matrix[0].size() - 1;
    for (const auto& row : augmented_matrix) {
        double sum = 0;
        for (int i = 0; i < m; i++) {
            sum += solution[i] * row[i];
        }
        if (abs(sum - row[m]) > epsilon) {
            return false;
        }
    }
    return true;
}

int gauss_jordan_elimination(std::vector<std::vector<double>> augmented_matrix,
                             std::vector<double>& solution)
{
    int n = augmented_matrix.size();
    int m = augmented_matrix[0].size() - 1;
    std::unordered_map<int, int> pivots;

    int row = 0;
    int col = 0;
    for (int row = 0, col = 0; col < m && row < n; col++) {
        // Partial pivoting.
        auto pivot = row;
        for (int i = row + 1; i < n; i++) {
            if (abs(augmented_matrix[pivot][col]) < abs(augmented_matrix[i][col])) {
                pivot = i;
            }
        }
        if (abs(augmented_matrix[pivot][col]) < epsilon) {
            // No pivot for the column.
            continue;
        }
        if (pivot != row) {
            swap(augmented_matrix[pivot], augmented_matrix[row]);
        }
        pivots[col] = row;
        // Forward elimination and back substitution.
        for (int i = 0; i < n; i++) {
            if (row != i) {
                auto multiplier = augmented_matrix[i][col] / augmented_matrix[row][col];
                for (int j = 0; j <= m; j++) {
                    augmented_matrix[i][j] -= multiplier * augmented_matrix[row][j];
                }
            }
        }
        row++;
    }

    solution.assign(n, 0);
    for (int i = 0; i < m; i++) {
        const auto& it = pivots.find(i);
        if (it != pivots.end()) {
            solution[i] = augmented_matrix[it->second][m] / augmented_matrix[it->second][i];
        }
    }
    if (!is_solution(augmented_matrix, solution)) {
        // No solutions
        return 0;
    }
    for (int i = 0; i < m; i++) {
        if (pivots.find(i) == pivots.end()) {
            // Infinitely many solutions
            return 2;
        }
    }
    // A unique solution
    return 1;
}

} // namespace mehara::mathematics::linalg
