// Copyright 2020 Nayeem Rafsan
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

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pair_int;

#define inf INT_MAX
// number of vertices
const int V = 4;
// storing the graph in a vector of pair<int , int>
vector<pair<int, int>> graph[V];

// adding edges to the graph with weight
void addEdge(int source, int target, int weight)
{
    // creating a pair of target, weight
    graph[source].push_back(make_pair(target, weight));
    // undirected graph
    graph[target].push_back(make_pair(source, weight));
}
void prims()
{
    // priority queue to sort the edges with minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    // assuming the source as 0, we can choose any
    int source = 0;
    // initially all edges must contain infinity
    vector<int> distance(V, inf);
    // distance from source to source =0
    distance[0] = 0;
    // initially all vertices as -1 as parent and 0 has parent 0
    vector<int> parent(V, -1);
    parent[0] = 0;
    // visited array to keep track of the tree
    vector<bool> visited(V, false);
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        // taking edge with minimum distance
        int source = pq.top().second;
        pq.pop();
        visited[source] = true;
        for (auto neighbour : graph[source]) {
            // taking neighbour of the source visiting it and if current
            // distance is smaller we update the distance and parent
            int v = neighbour.first;
            int current_dist = neighbour.second;
            if (visited[v] != true && distance[v] > current_dist) {
                pq.push(make_pair(distance[v], v));
                distance[v] = current_dist;
                parent[v] = source;
            }
        }
    }
    // printing the Minimum spanning tree
    for (int i = 0; i < V; ++i) {
        cout << parent[i] << " " << i << endl;
    }
}

int main()
{
    addEdge(0, 1, 1);
    addEdge(0, 2, 4);
    addEdge(0, 3, 3);
    addEdge(1, 3, 2);
    addEdge(2, 3, 5);
    prims();
    return 0;
}

/*

(0) ----1--- (1)
|	\		 |
4	   3	2
|	     \	|
(2)---5---(3)

MST for this graph---->

(0) ----1--- (1)
|			 |
4	   		2
|	     	|
(2)        (3)

*/