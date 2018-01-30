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

#include <unordered_map>
#include <unordered_set>

using namespace std;

class DirectedGraph {

	long number_of_edges;
	unordered_map<int, unordered_set<int>> adjacency_list_;
	unordered_map<int, int> in_degree_;

public:

	bool Adjacent(int source_vertex, int target_vertex);

	unordered_set<int> Neighbours(int vertex);

	void AddVertex(int vertex);

	void RemoveVertex(int vertex);

	void AddEdge(int source_vertex, int target_vertex);

	void RemoveEdge(int source_vertex, int target_vertex);

};