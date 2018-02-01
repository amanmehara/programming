/*

 Copyright 2018 Aman Mehara

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 */

#include "depth_first_traversal.h"

#include <stack>

void DepthFirstTraversal::Recur(DirectedGraph &directed_graph, int vertex, unordered_set<int> &visited) {

	visited.insert(vertex);

	for (int neighbour : directed_graph.Neighbours(vertex)) {
		if (!visited.count(neighbour)) {
			Recur(directed_graph, neighbour, visited);
		}
	}

}

void DepthFirstTraversal::TraverseIteratively(DirectedGraph directed_graph, int source_vertex) {

	unordered_set<int> visited;
	stack<int> frontier;

	frontier.push(source_vertex);

	while (!frontier.empty()) {

		int s = frontier.top();
		frontier.pop();

		if (!visited.count(s)) {
			visited.insert(s);

			for (int neighbour : directed_graph.Neighbours(s)) {
				frontier.push(neighbour);
			}
		}

	}

}

void DepthFirstTraversal::TraverseRecursively(DirectedGraph directed_graph, int source_vertex) {

	unordered_set<int> visited;

	Recur(directed_graph, source_vertex, visited);

}