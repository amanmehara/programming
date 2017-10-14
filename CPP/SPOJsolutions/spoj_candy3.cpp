#include <iostream>
using namespace std;

int main()
{
    long long t,n;
    cin>>t;
    while(t--){
    	long long sum = 0,no;
    	//cin.ignore('\n');
    	cin>>n;
    	long long im = n;
    	while(n--){
    		cin>>no;
    		//cout<<no<<" ";
    		sum+=no;
    		sum = sum%im;
    	}
    	//cout<<sum<<endl;
    	if (sum%im == 0)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    
    return 0;
}

