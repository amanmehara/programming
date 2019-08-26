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

#include <queue>
#include <utility>
#include <vector>

void flood_fill(std::vector<std::vector<char>>& board, int _r, int _c,
                char target, char replacement) {
    if (target == replacement || board[_r][_c] != target) {
        return;
    }
    std::queue<std::pair<int, int>> frontier;
    board[_r][_c] = replacement;
    frontier.emplace(_r, _c);
    while (!frontier.empty()) {
        auto point = frontier.front();
        frontier.pop();
        if (point.first - 1 >= 0 &&
            board[point.first - 1][point.second] == target) {
            board[point.first - 1][point.second] = replacement;
            frontier.emplace(point.first - 1, point.second);
        }
        if (point.second - 1 >= 0 &&
            board[point.first][point.second - 1] == target) {
            board[point.first][point.second - 1] = replacement;
            frontier.emplace(point.first, point.second - 1);
        }
        if (point.first + 1 < board.size() &&
            board[point.first + 1][point.second] == target) {
            board[point.first + 1][point.second] = replacement;
            frontier.emplace(point.first + 1, point.second);
        }
        if (point.second + 1 < board[0].size() &&
            board[point.first][point.second + 1] == target) {
            board[point.first][point.second + 1] = replacement;
            frontier.emplace(point.first, point.second + 1);
        }
    }
};

void solve(std::vector<std::vector<char>>& board) {
    if (board.size() == 0) {
        return;
    }

    for (auto index = 0; index < board.size(); index++) {
        flood_fill(board, index, 0, 'O', 'Q');
        flood_fill(board, index, board.size() - index - 1, 'O', 'Q');
    }

    for (auto index = 0; index < board[0].size(); index++) {
        flood_fill(board, 0, index, 'O', 'Q');
        flood_fill(board, board[0].size() - index - 1, index, 'O', 'Q');
    }

    for (auto& row : board) {
        for (auto& cell : row) {
            cell = cell == 'Q' ? 'O' : 'X';
        }
    }
}
