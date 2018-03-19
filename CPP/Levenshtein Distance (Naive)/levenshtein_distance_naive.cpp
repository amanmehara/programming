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
#include "levenshtein_distance_naive.h"

#include <algorithm>
#include <vector>

int LevenshteinDistance::Distance(int sequence1_index, int sequence2_index) {

	if (!std::min(sequence1_index, sequence2_index)) {
		return std::max(sequence1_index, sequence2_index);
	}

	int indicator = (sequence1_[sequence1_index - 1] == sequence2_[sequence2_index - 1]) ? 0 : 1;

	return std::min(
		std::min(
			1 + Distance(sequence1_index - 1, sequence2_index),
			1 + Distance(sequence1_index, sequence2_index - 1)
		),
		indicator + Distance(sequence1_index - 1, sequence2_index - 1)
	);
}

int LevenshteinDistance::Distance() {

	int sequence1_size = static_cast<int>(sequence1_.size());
	int sequence2_size = static_cast<int>(sequence2_.size());

	return Distance(sequence1_size, sequence2_size);

}