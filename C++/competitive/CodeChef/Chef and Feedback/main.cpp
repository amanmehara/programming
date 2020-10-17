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
#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve()
{
    string s;
    cin>>s;
    auto i=s.find("010");
    auto j=s.find("101");

    if(i<s.size()||j<s.size()){
        cout<<"Good";
        return ;
    }
    cout<<"Bad";
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
