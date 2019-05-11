#include <iostream>
using namespace std;

int main() {
    int i,j,c,n;
    cin>>n;
    c=n;
    for(i=2;i*i<=n;++i){
        for(j=i;i*j<=n;++j)
            c++;
    }
    cout<<c;
	// your code goes here
	return 0;
}
