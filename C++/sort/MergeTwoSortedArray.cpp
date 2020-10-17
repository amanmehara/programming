  
// Copyright 2020 Suyash Patel
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
void merge(int fi[],int se[],int u1, int v1);//declared merge function
//main function
int main() {

//input of array
    int f[]={11,16,21,45};
    int s[]={6,8,8,11,16};
   int s1=sizeof(f)/sizeof(f[0]);
    int s2=sizeof(s)/sizeof(s[0]);
	merge(f,s,s1,s2);
	return 0;
}
//merge function
void merge(int fi[],int se[],int u1, int v1)
{
 int i=0;
 int j=0;
 while(i<u1&&j<v1)
  {
   if(fi[i]<se[j])
    {
        cout<<fi[i++]<<" ";
    }
    else
      {
          cout<<se[j++]<<" ";
      }
 
  }
 while(i<u1){cout<<fi[i++]<<" "; }
  while(j<v1){cout<<se[j++]<<" "; }
}
