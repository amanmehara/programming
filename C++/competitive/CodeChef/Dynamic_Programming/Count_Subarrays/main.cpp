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

#include<bits/stdc++.h>
#define ll long long

using namespace std;


void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll dp[n];
    fill(dp,dp+n,1ll);
    ll ans = 1;
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]) dp[i] += dp[i-1];
        ans += dp[i];
    }
    cout<< ans << "\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
