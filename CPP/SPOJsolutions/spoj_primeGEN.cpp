#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
										///took me 8 days to solve :p
typedef long long typ;

int main() {
	int t;
	cin>>t;
	while(t--){
		typ m,n,k;
		cin>>m>>n;
		typ sq = sqrt(n);
		typ dubsq = sqrt(sq);
		vector<bool> prime(sq+1);
		vector<bool> myprime(n-m+1);
		fill(prime.begin(),prime.end(),true);
		fill(myprime.begin(),myprime.end(),true);
		prime[0]=prime[1]=false;
		for(int i=2;i<=dubsq;++i){
			if(prime[i]){
				for(int j=i*i;j<=sq;j+=i){
					prime[j] = false;
				}
			}
		}
			//for(int i=0;i<=sq;++i)
			//if(prime[i]) {cout<<i<<endl;
				//}
		
		for(int i=0;i<=sq;++i){
			if(prime[i]){
				k = ((int)(m/i)*i);
				//cout<<"K:"<<k<<endl;
				for(int x=k;x<=n;x+=i){
						if(x>=m && x!=i) {
							//cout<<"index:"<<x<<endl;
							myprime[x-m] = false; 
						}
				}
			}
		}
		//typ g=0;				///comented parts are counter!
		for(int i=0;i<n-m+1;++i)
			if(myprime[i]) {
				if(i+m!=1){ cout<<i+m<<endl;		// base case ignore for 1
							//g++;
						}
				}
		//cout<<g<<endl;
		cout<<endl;
	}
	return 0;
}
