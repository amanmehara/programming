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

#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::int64_t total_cells;
    std::int64_t target_cell;
    std::cin >> total_cells >> target_cell;
    std::vector<int> portals(total_cells - 1);
    for (auto i = 0; i < total_cells - 1; i++) {
        std::cin >> portals[i];
    }
    std::int64_t current_cell = 1;
    while (true) {
        if (current_cell == target_cell) {
            std::cout << "YES\n";
            return 0;
        }
        else if (current_cell > target_cell) {
            std::cout << "NO\n";
            return 0;
        }
        current_cell += portals[current_cell - 1];
    }
}