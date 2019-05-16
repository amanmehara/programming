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

#include <memory>
#include <unordered_set>

namespace mehara::graph {

template <class T> class graph {
  public:
    virtual bool adjacent(std::shared_ptr<T> source_vertex,
                          std::shared_ptr<T> target_vertex) = 0;

    virtual std::unordered_set<std::shared_ptr<T>>
    neighbors(std::shared_ptr<T> vertex) = 0;

    virtual void add_vertex(std::shared_ptr<T> vertex) = 0;

    virtual void remove_vertex(std::shared_ptr<T> vertex) = 0;

    virtual void add_edge(std::shared_ptr<T> source_vertex,
                          std::shared_ptr<T> target_vertex) = 0;

    virtual void remove_edge(std::shared_ptr<T> source_vertex,
                             std::shared_ptr<T> target_vertex) = 0;

    virtual ~graph() {}
};

} // namespace mehara::graph

#endif // MEHARA_GRAPH_H_
