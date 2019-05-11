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
#include "longest_increasing_subsequence_tabulation.h"

#include <algorithm>
#include <vector>

LongestIncreasingSubsequence::LongestIncreasingSubsequence(std::vector<int> sequence) {

	length_ = 0;
	sequence_ = sequence;
	table_ = std::vector<int>(sequence_.size() + 1, 1);

	for (int sequence_index = 0; sequence_index < sequence_.size(); sequence_index++) {
		for (int previous_index = 0; previous_index < sequence_index; previous_index++) {
			if (sequence_[sequence_index] > sequence_[previous_index] && table_[sequence_index] < table_[previous_index] + 1) {
				table_[sequence_index] = table_[previous_index] + 1;
			}
		}
	}

	for (int sequence_index = 0; sequence_index < sequence_.size(); sequence_index++) {
		length_ = std::max(length_, table_[sequence_index]);
	}

}

int LongestIncreasingSubsequence::Length() {
	return length_;
}