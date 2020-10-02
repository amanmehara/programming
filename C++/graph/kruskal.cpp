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
#define INF INT_MAX
using namespace std;

// declaration
int number_of_nodes, number_of_edges;
int parent[1000];
// Creating a Edge structure because Kruskal is a edge based algorithm
struct Edge {
    int source, target, weight;
};

bool compare(Edge u, Edge v) { return u.weight < v.weight; }
// kruskal is based on union, find property
int find(int p)
{
    if (parent[p] == p) {
        return p;
    }
    return find(parent[p]);
}

void kruskal(vector<Edge> edges)
{
    // sorting the edges by weight (non decreasing order)
    sort(edges.begin(), edges.end(), compare);
    // initally all parents are equal to 0
    iota(parent, parent + number_of_nodes, 0);
    // to save the edges of spanning tree
    vector<Edge> MST;

    for (int i = 0; i < number_of_edges; i++) {
        Edge edge = edges[i];
        int u = find(edge.source);
        int v = find(edge.target);
        // union method
        // if both are disjoint then join them
        if (u != v) {
            MST.push_back(edge);
            parent[u] = v;
        }
    }
    // printing the MST
    for (int i = 0; i < MST.size(); ++i) {
        cout << MST[i].source << " " << MST[i].target << "\n";
    }
}
int main()
{
    number_of_nodes = 4;
    number_of_edges = 5;

    // to store the edges
    vector<Edge> edges;

    Edge edge1, edge2, edge3, edge4, edge5;

    edge1.source = 0;
    edge1.target = 1;
    edge1.weight = 1;
    edge2.source = 0;
    edge2.target = 2;
    edge2.weight = 4;
    edge3.source = 0;
    edge3.target = 3;
    edge3.weight = 3;
    edge4.source = 2;
    edge4.target = 3;
    edge4.weight = 5;
    edge5.source = 1;
    edge5.target = 3;
    edge5.weight = 2;
    edges.push_back(edge1);
    edges.push_back(edge2);
    edges.push_back(edge3);
    edges.push_back(edge4);
    edges.push_back(edge5);
    kruskal(edges);
    return 0;
}

/*

parenthesis represents vertex and others are weight
(0) ----1---(1)
|   \        |
4      3     2
|        \   |
(2)---5----(3)

MST for this graph---->

(0) ----1--- (1)
|             |
4             2
|             |
(2)         (3)

*/