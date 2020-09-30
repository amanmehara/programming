        // Copyright 2020  Avinash  Trivedi
	
	// Licensed under the Apache License, Version 2.0 (the "License");
	// you may not use this file except in compliance with the License.
	// You may obtain a copy of the License at
	//
	//     http://www.apache.org/licenses/LICENSE-2.0
	//
	// Unless required by applicable law or agreed to in writing, software
	// distributed under the License is distributed on an "AS IS" BASIS,
	// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	// See the License for the specific language governing permissions and
	// limitations under the License.

 class Solution
 {
 	public:
 		int maxSubArray(vector<int> &nums)
 		{
 			int cs = 0;
 			int ms = INT_MIN;
 			// if size of array is 1 return that elemnt .
 			if (nums.size() == 1)
 			{
 				return nums[0];
 			}

 			//Linearly traverse the array and add to the current sum variable and take maximum .
 			for (int i = 0; i < nums.size(); i++)
 			{
 				cs = cs + nums[i];

 				ms = max(cs, ms);
 				if (cs < 0)
 				{
 					cs = 0;
 				}
 			}

 			return ms;
 		}
 };