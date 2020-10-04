// Copyright 2020 Nilay Rajderkar

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "counting_sort.h"

#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 
#define LIMIT 255 

//sorting the given string in alphabetical order
void countSort(char arr[]) 
{ 
	//the array having sorted characters
	char output[strlen(arr)]; 

	// array to count individual characters
	int count[LIMIT + 1], i; 
	memset(count, 0, sizeof(count)); 

	//to store count
	for (i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= LIMIT; ++i) 
		count[i] += count[i - 1]; 

	// building the output array
	for (i = 0; arr[i]; ++i) { 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	} 

	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
} 


int main() 
{ 
	char arr[] = "thisisabrowncow"; 

	countSort(arr); 

	cout << "The final sorted array is" << arr; 
	return 0; 
}  //end of code 






