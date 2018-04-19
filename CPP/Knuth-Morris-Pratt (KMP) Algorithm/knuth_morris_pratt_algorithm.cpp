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
#include "knuth_morris_pratt_algorithm.h"

#include <string>
#include <vector>

KMPAlgorithm::KMPAlgorithm(std::string pattern) {

	pattern_ = pattern;
	dfa_ = std::vector<std::vector<int>>(256, std::vector<int>(pattern_.size(), 0));

	dfa_[pattern_[0]][0] = 1;

	for (int state_x = 0, pattern_index = 1; pattern_index < pattern_.size(); pattern_index++) {

		for (int radix_index = 0; radix_index < dfa_.size(); radix_index++) {
			dfa_[radix_index][pattern_index] = dfa_[radix_index][state_x];
		}

		dfa_[pattern_[pattern_index]][pattern_index] = pattern_index + 1;
		state_x = dfa_[pattern_[pattern_index]][state_x];

	}

}

int KMPAlgorithm::Search(std::string text) {

	int pattern_index, text_index;

	for (pattern_index = 0, text_index = 0; pattern_index < pattern_.size() && text_index < text.size(); text_index++) {
		pattern_index = dfa_[text[text_index]][pattern_index];
	}

	if (pattern_index == pattern_.size()) {
		return text_index - pattern_index;
	}

	return text.size();

}