// Copyright 2020 Avinash Trivedi
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


class Solution
{
	public:
		int maxProfit(vector<int> &prices)
		{
			int sum = 0;
			//If the number of element in the array are zero or one just return zero.
			if (prices.size() == 1 or prices.size() == 0)
			{
				return 0;
			}

			//Traverse the array and compare the consecutive two elements .
			for (int i = 0; i < prices.size() - 1; i++)
			{
				// If first consecuitve element is less than second subtract both and add in the sum varibale. 
				if (prices[i] < prices[i + 1])
				{
					sum += prices[i + 1] - prices[i];

				}
			}

			//Finally return the sum.
			return sum;

		}
};
