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


int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n+1];
        map<ll,ll>mp;
        ll ans=0,vc=0,t=1;
        for(ll  i=0;i<n;i++){
            cin>>a[i];
        }

        ll col[n+1][n+1]={0};
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                col[i][j] = 0;
            }
        }
        for(ll i=0;i<n;i++){
            mp.clear();
            for(ll j=i;j<n;j++){
                col[i][j]=(j==0)?0:col[i][j-1];
                if(mp.count(a[j])){
                    if(mp[a[j]]==1){
                        col[i][j]++;
                    }
                    col[i][j]++;
                }
                mp[a[j]]++;
            }
        }

        ans=1e18;
        ll table=100;
        ll dp[101][1001]={0};
        for(ll i=0;i<=table;i++){
            for(ll j=0;j<=table;j++){
                dp[i][j]=0;
            }
        }
        for(ll i=0;i<n+1;i++)
        {
            dp[1][i]=col[0][i-1];
        }
        for(ll i=2;i<=table;i++){
            dp[i][1]=0;
        }
        for(ll i=2;i<=table;i++){
            for(ll j=2;j<=n;j++){
                ll best=1e18;
                for(ll p=1;p<j;p++){
                    best=min(best,dp[i-1][p]+col[p][j-1]);
                }
                dp[i][j]=best;
            }
        }
        for(table=1;table<=100;table++){
            ans=min(table*k+dp[table][n],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
