'''
Copyright 2020 Puneet Garg

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

'''

def SieveOfEratosthenes(n):
    isPrime = [True for i in range(n)]
    primes = [] # list to store all prime numbers
    for i in range(2, n+1):
        if isPrime[i-1]:
            primes.append(i)
            j = i*i
            # if i is prime then we will set all its multiples upto n to False.
            while(j <= n):
                isPrime[j-1] = False
                j += i
    return primes

# driver program to test SieveOfEratosthenes function
n = 50
print(SieveOfEratosthenes(n))

# output : [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
