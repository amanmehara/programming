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
#include<vector>
#include<iterator>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m)
{
    int temp;
    vector <int> unfinished, completed, total, chef, asst;
    for(int i = 0; i<m;i++){
        cin>>temp;
        completed.push_back(temp);
    }
    for(int i=1;i<=n;++i){
        total.push_back(i);
    }
    sort(total.begin(), total.end());
    sort(completed.begin(), completed.end());
    set_difference(
                   total.begin(),
                   total.end(),
                   completed.begin(),
                   completed.end(),
                   inserter(unfinished, unfinished.begin())
    );
    sort(unfinished.begin(), unfinished.end());
    int count = 0;
    for(auto i:unfinished){
        if(count%2==0) chef.push_back(i);
        else asst.push_back(i);
        count++;
    }

    // Printing
    for(auto i:chef) cout << i <<' '; cout<<'\n';
    for(auto i:asst) cout << i <<' '; cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m,temp,counter=1;
    vector<int> chef,asst;
    cin>>t;
    while(t--){
        cin>>n>>m;
        solve(n,m);
    }
    return 0;
}
