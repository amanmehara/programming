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
#include "subset_sum_problem_tabulation.h"

#include <vector>

bool SubsetSumProblem::SubsetSum(int elements, int sum) {

	std::vector<std::vector<bool>> table(elements + 1, std::vector<bool>(sum + 1, false));

	for (int i = 0; i <= elements; i++) {
		table[i][0] = true;
	}

	for (int element_index = 1; element_index <= elements; element_index++) {
		for (int sum_index = 1; sum_index <= sum; sum_index++) {
			bool sum_excluding_current = table[element_index - 1][sum_index];

			bool sum_including_current = false;
			if (sum_index >= set_[element_index - 1]) {
				sum_including_current = table[element_index - 1][sum_index - set_[element_index - 1]];
			}

			table[element_index][sum_index] = sum_excluding_current || sum_including_current;
		}
	}

	return table[elements][sum];

}

bool SubsetSumProblem::SubsetSum(int sum) {

	int set_size = static_cast<int>(set_.size());

	return SubsetSum(set_size, sum);

}