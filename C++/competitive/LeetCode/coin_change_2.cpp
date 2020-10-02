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
        //create a dp table
        //rows represent index of coins in the 'coins' vector whereas first row represent no coins
        //columns represent amount from 0 to amount
        int dp [coins.size()+1][amount+1];
        for(int i=0;i<coins.size()+1;i++){
            for(int j=0;j<amount+1;j++){

                //for first column the value should be 1 stating that amount 0 can be formed in one way i.e. no coins 
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }

                //for first row and columns>0 the value will be 0 as no amount greater than 0 can be formed by number of coins = 0 i.e. no coins
                if(i==0){
                    dp[i][j]=0;
                    continue;
                }

                //case: we not select current denomination
                int a = dp[i-1][j];

                //case: we select current denomination and check number of ways amount-currentDenomination can be formed
                //here 0 means that the current denomination is greater tha column amount
                int b = coins[i-1]>j?0:dp[i][j-coins[i-1]];
                
                //add ways of forming an amount in both the above cases
                dp[i][j]=a+b;
                
            }
           
        }
        
        //dp[coins.size][amount] represents the total number of ways for that required amount considering all denominations
        return dp[coins.size()][amount]; 
    }
};

