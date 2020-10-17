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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[10000];
        ll min=1000000000000, min2=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            if(k%a[i]==0){
                ll temp=k/a[i]-1;
                if(temp<min){
                    min=temp;
                    min2=a[i];
                }
            }
        }
        cout<<min2<<endl;
    }
	return 0;
}
