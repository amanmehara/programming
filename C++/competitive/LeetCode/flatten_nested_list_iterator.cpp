// Copyright 2019 Aman Mehara
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

#include <stack>
#include <tuple>
#include <vector>

class nested_integer {
  public:
    bool is_integer() const;

    int get_integer() const;

    const std::vector<nested_integer>& get_list() const;
};

class nested_iterator {
  public:
    nested_iterator(const std::vector<nested_integer>& nested_list) {
        stack_.emplace(nested_list.begin(), nested_list.end());
    }

    int next() {
        auto& [it, end] = stack_.top();
        auto _next = it->get_integer();
        it++;
        return _next;
    }

    bool has_next() {
        while (!stack_.empty()) {
            auto& [it, end] = stack_.top();
            if (it == end) {
                stack_.pop();
                if (!stack_.empty()) {
                    auto& [it, end] = stack_.top();
                    it++;
                }
            } else if (it->is_integer()) {
                return true;
            } else {
                stack_.emplace(it->get_list().begin(), it->get_list().end());
            }
        }
        return false;
    }

  private:
    std::stack<std::tuple<std::vector<nested_integer>::iterator,
                          std::vector<nested_integer>::iterator>>
        stack_;
};