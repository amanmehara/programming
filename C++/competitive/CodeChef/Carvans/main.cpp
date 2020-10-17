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

int find()
{
    int no, q=0;
    cin>>no;
    int count = no;
    long long int speed[no];
    for(int i=0;i<no;i++)
        cin>>speed[i];

    for(int i=1;i<no;i++)
	{
		q=0;
		for(int j=0;j<i;j++)
		{
			if(speed[i]>speed[j])
			q=1;
		}
		if(q==1)
		count=count-1;
    }
    return count;
}


int main()
{
    int t,i=0;
    cin>>t;
    int temp = t;
    int ans[t];
    while(t--){
        ans[i]=find();
        i++;
    }
    for(int i=0;i<temp;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
