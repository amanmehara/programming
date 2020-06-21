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

#include <algorithm>
#include <vector>

int lengthOfLIS(std::vector<int>& sequence)
{
    if (sequence.empty()) {
        return 0;
    }
    std::vector<int> dp(sequence.size(), 1);
    int length_lis = 0;
    for (int i = 0; i < sequence.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }
        }
        length_lis = std::max(dp[i], length_lis);
    }
    return length_lis;
}