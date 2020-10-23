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
#include <cstring>
using namespace std;
int ans;
int v[200005];
void solve()
{
    for(int i = 1;i<= 200000; i++)
        v[i] = 0;
    int n,j,l,lmax = 0,dr = 1,current;
    scanf("%d",&n);
    scanf("%d%d",&v[1],&v[2]);
    dr = 2;
    current = v[2]-v[1];
    l = 2;
    for(j=3;j<=n;j++)
    {
        scanf("%d",&v[j]);
        dr++;
        if(v[dr]-v[dr-1] == current)
            l++;
        else
        {
            if(l>lmax)
                lmax = l;
            l = 2;
            current = v[dr] - v[dr-1];
        }
    }
    if(lmax == 0 || lmax < l)
        lmax = l;
    ans = lmax;
}
int main()
{
    int t,i=0;
    scanf("%d",&t);
    while(t--)
    {
        i++;
        solve();
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
