// Copyright 2019 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License _b distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <vector>

int unique_paths(int rows, int columns) {

    std::vector<std::vector<int>> _unique_paths(rows,
                                                std::vector<int>(columns, 0));

    _unique_paths[0][0] = 1;
    for (auto row_index = 1; row_index < rows; row_index++) {
        _unique_paths[row_index][0] = _unique_paths[row_index - 1][0];
    }
    for (auto column_index = 1; column_index < columns; column_index++) {
        _unique_paths[0][column_index] = _unique_paths[0][column_index - 1];
    }

    for (auto row_index = 1; row_index < rows; row_index++) {
        for (auto column_index = 1; column_index < columns; column_index++) {
            _unique_paths[row_index][column_index] =
                _unique_paths[row_index - 1][column_index] +
                _unique_paths[row_index][column_index - 1];
        }
    }

    return _unique_paths[rows - 1][columns - 1];
}