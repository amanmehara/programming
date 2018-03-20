/*
 * Copyright 2018 Aman Mehara
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include  "directed_graph.h"

#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <utility>

bool DirectedGraph::Adjacent(int source_vertex, int target_vertex) {
	return adjacency_list_.count(source_vertex) && adjacency_list_.find(source_vertex)->second.count(target_vertex);
}

unordered_set<int> DirectedGraph::Neighbours(int vertex) {
	if (adjacency_list_.count(vertex)) {
		return adjacency_list_.find(vertex)->second;
	}
	else {
		throw invalid_argument("Vertex not found in the Graph.");
	}
}

void DirectedGraph::AddVertex(int vertex) {
	adjacency_list_.insert(make_pair<>(vertex, unordered_set<int>()));
}

void DirectedGraph::RemoveVertex(int vertex) {
	if (adjacency_list_.count(vertex)) {
		adjacency_list_.erase(vertex);
		for (pair<int, unordered_set<int>> entry : adjacency_list_) {
			entry.second.erase(vertex);
		}
	}
}

void DirectedGraph::AddEdge(int source_vertex, int target_vertex) {
	if (adjacency_list_.count(source_vertex) && adjacency_list_.count(target_vertex)) {
		adjacency_list_.find(source_vertex)->second.insert(target_vertex);
	}
	else {
		throw invalid_argument("Vertex not found in the Graph.");
	}
}

void DirectedGraph::RemoveEdge(int source_vertex, int target_vertex) {
	if (adjacency_list_.count(source_vertex)) {
		adjacency_list_.find(source_vertex)->second.erase(target_vertex);
	}
}