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
#include "0_1_knapsack_problem_tabulation.h"

#include <algorithm>
#include <vector>

#include "item.h"

int ZeroOneKnapsackProblem::MaximumValue(int items, int weight) {

	std::vector<std::vector<int>> table(items + 1, std::vector<int>(weight + 1, 0));

	for (int item_index = 1; item_index <= items; item_index++) {
		for (int weight_index = 0; weight_index <= weight; weight_index++) {

			int value_excluding_current = table[item_index - 1][weight_index];

			int value_including_current = 0;
			if (weight_index >= items_[item_index - 1].Weight()) {
				value_including_current = items_[item_index - 1].Value() + table[item_index - 1][weight_index - items_[item_index - 1].Weight()];
			}

			table[item_index][weight_index] = std::max(value_excluding_current, value_including_current);

		}
	}

	return table[items][weight];

}

int ZeroOneKnapsackProblem::MaximumValue(int weight) {

	int item_size = static_cast<int>(items_.size());

	return MaximumValue(item_size, weight);

}