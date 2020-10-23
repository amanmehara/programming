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
#include <vector>
using namespace std;

bool check(vector<int> &arr, int mid, int k)
{
    int cnt = 0;
    for(int i=1; i<arr.size(); i++)
    {
        int diff = arr[i]-arr[i-1];
        int sessNeeded = (diff-1)/mid;
        cnt += sessNeeded;
        if(cnt > k)
            return false;
    }
    return true;
}



int solve()
{
    int n, k;
    scanf("%d%d",&n,&k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int maxDiff = 0;
    int ans = 0;
    for(int i=1; i<n; i++)
        maxDiff = max(maxDiff,arr[i]-arr[i-1]);
    if (maxDiff==1)
        return 1;
        //here comes binary search logic
    int s = 1, e = maxDiff;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(check(arr,mid,k))
        {
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;
    }
    return ans;
}

int main()
{
    int t,x;
    scanf("%d",&t);
    int i = 1;
    while(t--)
    {
        x = solve();
        printf("Case #%d: %d\n",i,x);
        i+=1;
    }
    return 0;
}
