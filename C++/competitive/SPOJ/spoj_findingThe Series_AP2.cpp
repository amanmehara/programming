/*
This problem requires dealing with formulas. We will call the series A,we have A[3] and A[N-2] and S. We don't know N yet. We know the formula for the sum which is ((A[1]+A[N])/2)*N it is the same as we replace A[1] with A[3]-2*D and a[N] with A[N-2]+2D which gives (A[3]-2D+A[n-2]+2D)/2*N whic equals to (A[3]+A[n-2])/2 * N =S where the N is the only unknown element so N=2*S/(A[3]+A[N-2])
After finding N we need to find D. so
A[3]=A[1]+2*D
A[n-2]=A[1]+(n-3)*d;
If we subtract the 2 equations above we will get the following
A[n-2]-A[3]=(n-5)*d where d=(A[n-2]-A[3])/(N-5)
*/

#include <iostream>
using namespace std;
typedef long long ll; 
int main() {
	ll n,d,s,a3,l3,a;
	int t;
	cin>>t;
	while(t--){
		cin>>a3>>l3>>s;
		n = (s*2)/(a3+l3);
		d = (l3-a3)/(n-5);
		//cout<<n<<" "<<d<<endl;
		a = a3 - 2*d;
		cout<<n<<endl;
		for(ll i=0;i<n;++i){
			cout<<a+i*d<<" ";
		}
	}
	// your code goes here
	return 0;
}
