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
#include "the_coin_change_problem.h"

#include <vector>

int CoinChangeCombinations(std::vector<int> coin_denominations, int amount) {

    int coin_denominations_size = static_cast<int>(coin_denominations.size());

    std::vector<std::vector<int>> table(coin_denominations_size, std::vector<int>(amount + 1, 0));

	for (int i = 0; i < coin_denominations_size; i++) {
		table[i][0] = 1;
	}

    for(int i = 0; i < coin_denominations_size; i++) {
        for(int j = 1; j <= amount; j++) {

			int combinations_excluding_current = 0;
			if (i > 0) {
				combinations_excluding_current = table[i - 1][j];
			}

			int combinations_including_current = 0;
			if (j >= coin_denominations[i]) {
				combinations_including_current = table[i][j - coin_denominations[i]];
			}

			table[i][j] = combinations_excluding_current + combinations_including_current;

        }
    }

    return table[coin_denominations_size -  1][amount];

}