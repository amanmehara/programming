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

#ifndef MEHARA_DIRECTED_GRAPH_H_
#define MEHARA_DIRECTED_GRAPH_H_

#include <unordered_map>
#include <unordered_set>

template <class T>
class DirectedGraph {

  public:
    bool Adjacent(T source_vertex, T target_vertex);

    std::unordered_set<T> Neighbours(T vertex);

    void AddVertex(T vertex);

    void RemoveVertex(T vertex);

    void AddEdge(T source_vertex, T target_vertex);

    void RemoveEdge(T source_vertex, T target_vertex);

  private:
    std::unordered_map<T, std::unordered_set<T>> adjacency_list_;
};

template <class T>
bool DirectedGraph<T>::Adjacent(T source_vertex, T target_vertex) {
    return adjacency_list_.count(source_vertex) && adjacency_list_.find(source_vertex)->second.count(target_vertex);
}

template <class T>
std::unordered_set<T> DirectedGraph<T>::Neighbours(T vertex) {
    if (adjacency_list_.count(vertex)) {
        return adjacency_list_.find(vertex)->second;
    } else {
        throw std::invalid_argument("Vertex not found in the Graph.");
    }
}

template <class T>
void DirectedGraph<T>::AddVertex(T vertex) {
    adjacency_list_.insert(std::make_pair<>(vertex, std::unordered_set<T>()));
}

template <class T>
void DirectedGraph<T>::RemoveVertex(T vertex) {
    if (adjacency_list_.count(vertex)) {
        adjacency_list_.erase(vertex);
        for (std::pair<T, std::unordered_set<T>> entry : adjacency_list_) {
            entry.second.erase(vertex);
        }
    }
}

template <class T>
void DirectedGraph<T>::AddEdge(T source_vertex, T target_vertex) {
    if (adjacency_list_.count(source_vertex) && adjacency_list_.count(target_vertex)) {
        adjacency_list_.find(source_vertex)->second.insert(target_vertex);
    } else {
        throw std::invalid_argument("Vertex not found in the Graph.");
    }
}

template <class T>
void DirectedGraph<T>::RemoveEdge(T source_vertex, T target_vertex) {
    if (adjacency_list_.count(source_vertex)) {
        adjacency_list_.find(source_vertex)->second.erase(target_vertex);
    }
}

#endif // MEHARA_DIRECTED_GRAPH_H_