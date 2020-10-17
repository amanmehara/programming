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

int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n,q;
	    cin>>n>>q;
	    while(q--){
	        ll l,r,v,sum=0;
	        cin>>l>>r>>v;
	        for(int i=l;i<=r;i++){
	            sum+=v;
	        }
	    }
	    cout<<sum<<endl;
	}
}
