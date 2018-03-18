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
#include"longest_common_subsequence_length.h"

#include <algorithm>
#include <vector>

int LongestCommonSubsequenceLength(std::vector<char> sequence1, std::vector<char> sequence2) {

	int sequence1_size = static_cast<int>(sequence1.size());
	int sequence2_size = static_cast<int>(sequence2.size());

	std::vector<std::vector<int>> table(sequence1_size + 1, std::vector<int>(sequence2_size + 1, 0));

	for (int index1 = 0; index1 < sequence1_size; index1++) {
		for (int index2 = 0; index2 < sequence2_size; index2++) {
			if (sequence1[index1] == sequence2[index2]) {
				table[index1 + 1][index2 + 1] = 1 + table[index1][index2];
			}
			else {
				table[index1 + 1][index2 + 1] = std::max(table[index1][index2 + 1], table[index1 + 1][index2]);
			}
		}
	}

	return table[sequence1_size][sequence2_size];

}