#include<iostream> 
using namespace std; 
  
unsigned long long factorial(unsigned long long n) 
{ 
    if (n == 0) 
    return 1; 
    return n * factorial(n - 1); 
} 
  
int main() 
{ 
    long long num;
	cin>>long;
    cout << "Factorial of " << num << " is " << factorial(num) << endl; 
    return 0; 
} 
