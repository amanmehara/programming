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

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int pc,pr,pcd,prd;
        cin>>pc>>pr;

        if(pc%9==0){
            pcd=pc/9;
        }
        else{
           pcd = pc/9 +1;
        }
        if(pr%9==0){
            prd=pr/9;
        }
        else{
            prd=pr/9+1;
        }
        if(pcd==prd)
            cout<<1<<" "<<prd<<endl;
        if(prd<pcd)
            cout<<1<<" "<<prd<<endl;
        if(pcd<prd)
            cout<<0<<" "<<pcd<<endl;
    }
    return 0;
}
