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
using namespace std;

int main() {
	// your code goes here
	long long t,x,y,k,n;
	long long cost, page;
	cin>>t;
	while(t--){
	    cin>>x>>y>>k>>n;
	    if(x <= y){
	        cout<<"LuckyChef"<<endl;
	        continue;
	    }
	    long long gap = x-y;
	    bool flag = false;
	    while(n--){
	        cin>>page>>cost;
	        if((cost<=k) && (page>=gap))
	            flag = true;
	    }
	    if(flag == false)
	        cout<<"UnluckyChef"<<endl;
        else
            cout<<"LuckyChef"<<endl;
	}

	return 0;
}
