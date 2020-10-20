// Copyright 2020 Pradeepsingh Bhati
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //here dp represents the previous denomination's operation values currently all set as 0 for default
        int dp[5001] = {0};
        
        //we can create 0 amount by just selecting no coins i.e. 1 way
        dp[0] = 1;
        for (int i=0;i<coins.size();i++) {
            for (int j = coins[i]; j <= amount; j++) {
                //here we have to add for two options : 1)if we select current denomination ( dp[currentAmount(j) - currentDenomination(coins[i])] )  + 
                 //2) if we dont select current denomination ( dp[currentAmount(j)] )
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount]; 
    }
};

