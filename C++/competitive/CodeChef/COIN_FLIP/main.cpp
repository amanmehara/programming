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

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int game;
        cin>>game;
        while(game--){
            int init, n, final, ans=0;
            cin>>init>>n>>final;
            if(n%2==0){
                ans/=2;
            }
            else{
                if(init==final){
                    ans = n/2;
                }
                else{
                    ans=n/2+1;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
