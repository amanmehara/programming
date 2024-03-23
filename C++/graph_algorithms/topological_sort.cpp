// Copyright 2024 Aman Mehara
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

#include "topological_sort.h"

#include <algorithm>
#include <deque>
#include <stdexcept>
#include <vector>

namespace mehara::graph {

using namespace std;

namespace {

void dfs(int vertex, const vector<vector<int>>& adjacency_list,
         vector<int>& colors, deque<int>& order)
{
    if (colors[vertex] == 2) {
        return;
    }
    if (colors[vertex] == 1) {
        throw logic_error("Graph has at least one cycle.");
    }
    colors[vertex] = 1;
    for (const auto& neighbour : adjacency_list[vertex]) {
        dfs(neighbour, adjacency_list, colors, order);
    }
    colors[vertex] = 2;
    order.push_front(vertex);
}

} // namespace

deque<int> dfs_topological_sort(const vector<vector<int>>& adjacency_list)
{
    int n = adjacency_list.size();
    vector<int> colors(n);
    deque<int> order;
    for (int i = 0; i < n; i++) {
        dfs(i, adjacency_list, colors, order);
    }
    return order;
}

deque<int>
kahns_algorithm_topological_sort(const vector<vector<int>>& adjacency_list)
{
    int n = adjacency_list.size();
    deque<int> order;
    vector<int> indegrees(n);
    for (int i = 0; i < n; i++) {
        for (const auto& neighbour : adjacency_list[i]) {
            indegrees[neighbour]++;
        }
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        int vertex = q.front();
        q.pop_front();
        order.push_back(vertex);
        for (const auto& neighbour : adjacency_list[vertex]) {
            indegrees[neighbour]--;
            if (indegrees[neighbour] == 0) {
                q.push_back(neighbour);
            }
        }
    }
    if (order.size() != n) {
        throw logic_error("Graph has at least one cycle.");
    }
    return order;
}

} // namespace mehara::graph
