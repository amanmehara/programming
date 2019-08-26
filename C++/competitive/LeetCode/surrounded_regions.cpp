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
#include <tuple>
#include <utility>
#include <vector>

void flood_fill(std::vector<std::vector<char>>& board,
                const std::tuple<int, int>& cell, 
                const char& target,
                const char& replacement) {
    auto [r, c] = cell;
    if (target == replacement || board[r][c] != target) {
        return;
    }
    std::queue<std::tuple<int, int>> frontier;
    board[r][c] = replacement;
    frontier.emplace(cell);
    while (!frontier.empty()) {
        auto [r, c] = frontier.front();
        frontier.pop();
        if (c - 1 >= 0 && board[r][c - 1] == target) {
            board[r][c - 1] = replacement;
            frontier.emplace(r, c - 1);
        }
        if (r - 1 >= 0 && board[r - 1][c] == target) {
            board[r - 1][c] = replacement;
            frontier.emplace(r - 1, c);
        }
        if (c + 1 < board[0].size() && board[r][c + 1] == target) {
            board[r][c + 1] = replacement;
            frontier.emplace(r, c + 1);
        }
        if (r + 1 < board.size() && board[r + 1][c] == target) {
            board[r + 1][c] = replacement;
            frontier.emplace(r + 1, c);
        }
    }
};

void solve(std::vector<std::vector<char>>& board) {
    if (board.size() == 0) {
        return;
    }

    for (auto index = 0; index < board.size(); index++) {
        flood_fill(board, {index, 0}, 'O', '#');
        flood_fill(board, {index, board[0].size() - 1}, 'O', '#');
    }

    for (auto index = 0; index < board[0].size(); index++) {
        flood_fill(board, {0, index}, 'O', '#');
        flood_fill(board, {board.size() - 1, index}, 'O', '#');
    }

    for (auto& row : board) {
        for (auto& cell : row) {
            cell = cell == '#' ? 'O' : 'X';
        }
    }
}
