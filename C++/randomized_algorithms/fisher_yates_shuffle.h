// Copyright 2020 Aman Mehara
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

#ifndef MEHARA_FISHER_YATES_SHUFFLE_H_
#define MEHARA_FISHER_YATES_SHUFFLE_H_

#include <cstdlib>
#include <utility>
#include <vector>

namespace mehara::random {

template <typename T>
void fisher_yates_shuffle(std::vector<T>& sequence)
{
    for (auto target_index = sequence.size() - 1; target_index > 0;
         target_index--) {
        const auto& random_index = std::rand() % (target_index + 1);
        if (random_index != target_index) {
            std::swap(sequence[random_index], sequence[target_index]);
        }
    }
}

} // namespace mehara::random

#endif // MEHARA_FISHER_YATES_SHUFFLE_H_
