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

#ifndef MEHARA_DFS_H_
#define MEHARA_DFS_H_

#include <exception>
#include <memory>
#include <stack>
#include <unordered_set>

#include "graph.h"

namespace mehara::graph {

enum class dfs_strategy { iterative, recursive };

template <class T>
void dfs(graph<T>& graph, std::shared_ptr<T> vertex,
         dfs_strategy dfs_strategy = dfs_strategy::iterative) {

    switch (dfs_strategy) {
    case dfs_strategy::iterative:
        iterative_dfs(graph, vertex);
        break;
    case dfs_strategy::recursive:
        recursive_dfs(graph, vertex);
        break;
    default:
        throw std::exception();
    }
}

template <class T>
void iterative_dfs(graph<T>& graph, std::shared_ptr<T> vertex) {

    std::unordered_set<std::shared_ptr<T>> visited;
    std::stack<std::shared_ptr<T>> frontier;

    frontier.push(vertex);

    while (!frontier.empty()) {
        vertex = frontier.top();
        frontier.pop();

        while (!visited.count(vertex)) {
            visited.insert(vertex);

            for (auto neighbor : graph.neighbors(vertex)) {
                frontier.push(neighbor);
            }
        }
    }
}

template <class T>
void recursive_dfs(graph<T>& graph, std::shared_ptr<T> vertex,
                   std::unordered_set<std::shared_ptr<T>>& visited =
                       std::unordered_set<std::shared_ptr<T>>()) {

    visited.insert(vertex);

    for (auto neighbor : graph.neighbors(vertex)) {
        if (!visited.count(neighbor)) {
            recursive_dfs(graph, neighbor, visited);
        }
    }
}

} // namespace mehara::graph

#endif // MEHARA_DFS_H_
