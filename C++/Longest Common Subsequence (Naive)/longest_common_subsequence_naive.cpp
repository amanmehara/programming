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
#include"longest_common_subsequence_naive.h"

#include <algorithm>
#include <vector>

int LongestCommonSubsequenceLength(std::vector<char>& sequence1, std::vector<char>& sequence2, int index1, int index2) {

	if (index1 < 0 || index2 < 0) {
		return 0;
	}

	if (sequence1[index1] == sequence2[index2]) {
		return 1 + LongestCommonSubsequenceLength(sequence1, sequence2, index1 - 1, index2 - 1);
	}
	else {
		return std::max(
			LongestCommonSubsequenceLength(sequence1, sequence2, index1 - 1, index2),
			LongestCommonSubsequenceLength(sequence1, sequence2, index1, index2 - 1)
		);
	}

}