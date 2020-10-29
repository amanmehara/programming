/*
 * 
 * Copyright 2020 Divya Garg
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
*/

import java.util.*;
public class SieveOfEratosthenes {
	public static void main(String args[]) {
		int n = 100;
		
		Boolean[] isPrime = new Boolean[n];
		Arrays.fill(isPrime, Boolean.TRUE); // initializing all values of boolean array to true
		
		for(int i = 2; i<n; i++) {
			if(isPrime[i-1]) {
				// if current number is prime print it and set all its multiples to false
				System.out.print(i + " "); 
				for(int j = i*i; j<=n; j+=i)
					isPrime[j-1] = false;
			}
		}
		
		/*
		 * Output :
		 * 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
		 */
		
	}
}
