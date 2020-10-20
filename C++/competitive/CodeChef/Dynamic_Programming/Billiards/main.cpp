// Copyright 2020 Shubham Kumar
//
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
#include <iostream>
#include <bits/stdc++.h>
#define Int long long
#define MOD 1000000009

using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<int> dp(1000001,0);
     dp[0] = 0;
     dp[1] = 0;
     dp[2] = 1;
     dp[3] = 1;
    for(int i=4;i<dp.size();i++){
        int op1=dp[i-2];
        int op2=dp[i-3];
        dp[i] = (dp[i]+op1+op2)%MOD;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
