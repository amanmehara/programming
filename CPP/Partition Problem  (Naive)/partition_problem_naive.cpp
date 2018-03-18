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
#include "partition_problem_naive.h"

#include <vector>

bool PartitionProblem::Partition(int elements, int sum) {

	if (!sum) {
		return true;
	}

	if (elements <= 0 || sum < 0) {
		return false;
	}

	return Partition(elements - 1, sum) || Partition(elements - 1, sum - set_[elements - 1]);

}

bool PartitionProblem::Partition() {

	int set_size = static_cast<int>(set_.size());

	int sum = 0;
	for (int i = 0; i < set_size; i++) {
		sum += set_[i];
	}

	if (sum % 2) {
		return false;
	}

	return Partition(set_size, sum / 2);

}