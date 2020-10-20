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
#define ll long long
using namespace std;

int main() {
	int t;
	vector<char> s={'S','S','E','C'};
	int vec[7] = {1,2,3,4,3,2,1};
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int r = n%7-1<0?n%7:n%7-1;
	    int val = vec[r];
	    int res;
        for(int i=0;i<val;i++){
            res = s[i];
            cout<<res<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
