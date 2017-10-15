#include <iostream>
#include <math.h>
using namespace std;

int rev(int n){
    int rever = 0;
    while (n != 0)
   {
      rever = rever * 10;
      rever = rever + n%10;
      n       = n/10;
   }
    return rever;
}

int main() {
    int t,n,m;
    cin>>t;
    while (t--){
    cin>>n>>m;
    cout<<rev(rev(n)+rev(m))<<endl;
    }
	return 0;
}

