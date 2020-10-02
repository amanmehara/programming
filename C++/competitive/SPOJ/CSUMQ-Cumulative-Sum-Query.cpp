// Copyright 2020  Avinash  Trivedi
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

 
#include <iostream>

 
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define intt long long
#define fori(n) for (ll i = 0; i < n; i++)
#define forj(n) for (ll j = 0; j < n; j++)
#define vl vector<ll> 
#define mod 1000000007
#define mp make_pair
#define vp vector<pair<int, int>>

 	int main()
 	{   
 	

 		intt n;
 		cin >> n;
 		intt a[n];
		//Taking the input array 

 		for (intt i = 0; i < n; i++)
 		{
 			cin >> a[i];
 		}
        //The next k lines each contain two numbers x and y which specify a query you must answer.

 		intt k;
 		cin >> k;
 		for (intt i = 0; i < k; i++)
 		{   //Range of query x,y.

 			intt x, y;
 			cin >> x >> y;
			//Declared the sum variable
			
 			intt sum = 0;
			//Traverse the array in the range x,y and keep adding the sum of elments which are in between the query range.

 			for (intt i = x; i <= y; i++)
 			{
 				sum += a[i];
 			}
            //Finally return the sum of those elements.
 			cout << sum << endl;
 		}

 		return 0;
 	}
	 