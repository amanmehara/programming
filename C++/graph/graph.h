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

#ifndef MEHARA_GRAPH_H_
#define MEHARA_GRAPH_H_

#include <unordered_set>

template <class T>
class graph {
  public:
    virtual bool adjacent(T source_vertex, T target_vertex) = 0;

    virtual std::unordered_set<T> neighbors(T vertex) = 0;

    virtual void add_vertex(T vertex) = 0;

    virtual void remove_vertex(T vertex) = 0;

    virtual void add_edge(T source_vertex, T target_vertex) = 0;

    virtual void remove_edge(T source_vertex, T target_vertex) = 0;

    virtual ~graph() {}
};

#endif // MEHARA_GRAPH_H_