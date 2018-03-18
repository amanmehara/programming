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
#include "0_1_knapsack_problem_naive.h"

#include <algorithm>
#include <vector>

#include "item.h"

int ZeroOneKnapsackProblem::MaximumValue(int item, int weight) {

	if (item <= 0 || weight <= 0) {
		return 0;
	}

	int value_excluding_current = MaximumValue(item - 1, weight);

	int value_including_current = 0;
	if (weight >= items_[item - 1].Weight()) {
		value_including_current = items_[item - 1].Value() + MaximumValue(item - 1, weight - items_[item - 1].Weight());
	}

	return std::max(value_excluding_current, value_including_current);

}

int ZeroOneKnapsackProblem::MaximumValue(int weight) {

	int item_size = static_cast<int>(items_.size());

	return MaximumValue(item_size, weight);

}