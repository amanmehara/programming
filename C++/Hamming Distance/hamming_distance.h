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
#ifndef MEHARA_HAMMING_DISTANCE_H_
#define MEHARA_HAMMING_DISTANCE_H_

#include <vector>

class HammingDistance {

	std::vector<char> sequence1_;
	std::vector<char> sequence2_;

public:

	HammingDistance(std::vector<char>& sequence1, std::vector<char>& sequence2) {
		sequence1_ = sequence1;
		sequence2_ = sequence2;
	}

	int Distance();

};

#endif  // MEHARA_HAMMING_DISTANCE_H_