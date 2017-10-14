//http://stackoverflow.com/questions/9052757/getchar-unlocked-vs-scanf-vs-cin

#define get_un  getchar_unlocked

#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long int ll;

int main() {
	ll n,k,c=0,t;
	scanf("%lld",&n);
	scanf("%lld",&k);
	//cout<<n<<endl<<k<<endl;
	while(n--){
		scanf("%lld",&t);
		if( t%k == 0)	c++;
	}
	
	cout<<c<<endl;
	return 0;
}

