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

#ifndef MEHARA_BFS_H_
#define MEHARA_BFS_H_

#include <exception>
#include <memory>
#include <queue>
#include <unordered_set>

#include "graph.h"

namespace mehara::graph {

template <class T> void bfs(graph<T>& graph, std::shared_ptr<T> vertex) {

    std::unordered_set<std::shared_ptr<T>> visited;
    std::queue<std::shared_ptr<T>> frontier;

    visited.insert(vertex);
    frontier.push(vertex);

    while (!frontier.empty()) {
        vertex = frontier.top();
        frontier.pop();

        for (auto neighbor : graph.neighbors(vertex)) {
            while (!visited.count(vertex)) {
                visited.insert(vertex);
                frontier.push(neighbor);
            }
        }
    }
}

} // namespace mehara::graph

#endif // MEHARA_BFS_H_
