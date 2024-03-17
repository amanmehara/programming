// Copyright 2024 Aman Mehara
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

#include "kmp_matcher.h"

#include <cmath>
#include <string>
#include <vector>

namespace mehara::string {

std::vector<int> compute_prefix_function(const std::string& pattern)
{
    int m = pattern.size();
    std::vector<int> pi(m);
    int k = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

std::vector<int> kmp_matcher(const std::string& text,
                             const std::string& pattern)
{
    std::vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    auto pi = compute_prefix_function(pattern);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            matches.push_back(i - m + 1);
            q = pi[q - 1];
        }
    }
    return matches;
}

} // namespace mehara::string
