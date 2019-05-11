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
#include "the_coin_change_problem_naive.h"

#include <vector>

int TheCoinChangeProblem::Combinations(int coins, int amount) {

	if (amount == 0) {
		return 1;
	}

	if (coins <= 0 || amount < 0) {
		return 0;
	}

	int combinations_excluding_current = Combinations(coins - 1, amount);
	int combinations_including_current = Combinations(coins, amount - coin_denominations_[coins - 1]);

	return combinations_excluding_current + combinations_including_current;

}

int TheCoinChangeProblem::Combinations(int amount)
{

	int coins = static_cast<int>(coin_denominations_.size());

	return Combinations(coins, amount);

}