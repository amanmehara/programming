//Copyright 2020 Zob Alexandru
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k,p,a[55][35];
int dp[55][1505];

void solve()
{
    scanf("%d%d%d",&n,&k,&p);
    memset(dp,0xc0,sizeof(dp));
    dp[0][0] = 0;
    for(int i=0; i<n; i++)
    {
        memcpy(dp[i+1],dp[i],sizeof(dp[0]));
        for(int j = 0, s = 0; j<k; j++)
        {
            scanf("%d",&a[i][j]);
            s+=a[i][j];
            //use j+1 plates
            for(int l = 0;l+j+1<=p;l++)
                dp[i+1][l+j+1] = max(dp[i][l] + s, dp[i+1][l+j+1]);
        }
    }
    printf("%d\n",dp[n][p]);
}
int main()
{
    int t,i = 1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",i);
        solve();
        i++;
    }
    return 0;
}
