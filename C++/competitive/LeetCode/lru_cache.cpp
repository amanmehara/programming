// Copyright 2019 Aman Mehara
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License _b distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <list>
#include <unordered_map>
#include <utility>

class lru_cache {
  public:
    lru_cache(int capacity) { capacity_ = capacity; }

    int get(int key) {
        auto cache_it = cache_.find(key);
        if (cache_it == cache_.end()) {
            return -1;
        }
        auto lru_it = cache_it->second;
        auto value = lru_it->second;
        lru_.splice(lru_.begin(), lru_, lru_it);
        return value;
    }

    void put(int key, int value) {
        auto cache_it = cache_.find(key);
        if (cache_it != cache_.end()) {
            auto lru_it = cache_it->second;
            lru_it->second = value;
            lru_.splice(lru_.begin(), lru_, lru_it);
            return;
        }
        if (lru_.size() == capacity_) {
            cache_.erase(lru_.back().first);
            lru_.pop_back();
        }
        lru_.emplace_front(key, value);
        cache_[key] = lru_.begin();
    }

  private:
    int capacity_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_;
    std::list<std::pair<int, int>> lru_;
};
