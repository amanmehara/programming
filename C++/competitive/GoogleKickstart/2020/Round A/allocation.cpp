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

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[100005];
int sol[105];
int main()
{
    int t,n,s,j,i,cnt = 0;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        memset(v, 0, sizeof(v));
        cnt = 0;
        scanf("%d%d",&n,&s);
        for(i=1;i<=n;i++)
            scanf("%d",&v[i]);
        //Greedy algorithm
        sort(v+1,v+n+1);
        for(i=1;i<=n;i++)
        {
            if(s-v[i]>=0)
            {
                s -= v[i];
                cnt++;
            }
            else
                break;
        }
        sol[j] = cnt;
    }
    for(j=1;j<=t;j++)
        printf("Case #%d: %d\n",j,sol[j]);
    return 0;
}
