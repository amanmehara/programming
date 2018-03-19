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
#include "hamming_distance.h"

#include <stdexcept>
#include <vector>

int HammingDistance::Distance() {

	if (sequence1_.size() != sequence2_.size()) {
		throw std::invalid_argument("Sequences are of different size.");
	}

	int sequence_size = static_cast<int>(sequence1_.size());

	int distance = 0;
	for (int sequence_index = 0; sequence_index < sequence_size; sequence_index++) {
		if (sequence1_[sequence_index] != sequence2_[sequence_index]) {
			distance = distance + 1;
		}
	}

	return distance;
}