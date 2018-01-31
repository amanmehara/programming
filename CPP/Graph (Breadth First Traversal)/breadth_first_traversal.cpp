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

#include "breadth_first_traversal.h"

#include <unordered_set>
#include <queue>

using namespace std;

void BreadthFirstTraversal::traverse(DirectedGraph directed_graph, int source_vertex) {

	unordered_set<int> visited;
	queue<int> frontier;

	visited.insert(source_vertex);
	frontier.push(source_vertex);

	while (!frontier.empty()) {

		int s = frontier.front();
		frontier.pop();

		for (int neighbour : directed_graph.Neighbours(s)) {
			if (!visited.count(neighbour)) {
				visited.insert(neighbour);
				frontier.push(neighbour);
			}
		}

	}

}