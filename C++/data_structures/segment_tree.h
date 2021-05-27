// Copyright 2021 Aman Mehara
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

#ifndef MEHARA_SEGMENT_TREE_H_
#define MEHARA_SEGMENT_TREE_H_

#include <algorithm>
#include <concepts>
#include <functional>
#include <vector>

namespace mehara {

template <typename T>
requires std::totally_ordered<T>
class segment_tree {
  public:
    segment_tree(const std::vector<T>& data, std::function<T(const T&, const T&)> function,
                 T identity)
        : function_(function), identity_(identity)
    {
        tree_ = std::vector<T>(data.size() * 4);
        size_ = data.size();
        build_tree(data, 0, 0, size_ - 1);
    }

    T query(int left, int right) { return query(0, 0, size_ - 1, left, right); }

    void update(int index, int value) { update(0, 0, size_ - 1, index, value); }

  private:
    std::vector<T> tree_;
    std::function<T(const T&, const T&)> function_;
    T identity_;
    int size_;

    void build_tree(const std::vector<T>& data, int node, int tree_left, int tree_right)
    {
        if (tree_left == tree_right) {
            tree_[node] = data[tree_left];
            return;
        }
        auto mid = tree_left + (tree_right - tree_left) / 2;
        build_tree(data, node * 2 + 1, tree_left, mid);
        build_tree(data, node * 2 + 2, mid + 1, tree_right);
        tree_[node] = function_(tree_[node * 2 + 1], tree_[node * 2 + 2]);
    }

    T query(int node, int tree_left, int tree_right, int query_left, int query_right)
    {
        if (query_left > query_right) {
            return identity_;
        }
        if (tree_left == query_left && tree_right == query_right) {
            return tree_[node];
        }
        int mid = tree_left + (tree_right - tree_left) / 2;
        return function_(
            query(2 * node + 1, tree_left, mid, query_left, std::min(query_right, mid)),
            query(2 * node + 2, mid + 1, tree_right, std::max(query_left, mid + 1), query_right));
    }

    void update(int node, int tree_left, int tree_right, int index, int value)
    {
        if (tree_left == tree_right) {
            tree_[node] = value;
            return;
        }
        int mid = tree_left + (tree_right - tree_left) / 2;
        if (index <= mid) {
            update(2 * node + 1, tree_left, mid, index, value);
        }
        else {
            update(2 * node + 2, mid + 1, tree_right, index, value);
        }
        tree_[node] = function_(tree_[node * 2 + 1], tree_[node * 2 + 2]);
    }
};

} // namespace mehara

#endif // MEHARA_SEGMENT_TREE_H_
