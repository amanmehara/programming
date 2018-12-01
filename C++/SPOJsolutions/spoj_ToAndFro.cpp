#include <iostream>
#include <math.h>
using namespace std;

int main() {
    string str;
    int n,m;
    while(1){
    cin>>m;
    if(m ==0 )  break;
    else{
	    cin>>str;
	    int strSIZE = str.size();
	    int n = ceil((float)strSIZE/(float)m);
	    char ar[n][m];
	    int k=0,j;
	    for(int i=0;i<n;++i){
	        if(i%2==0){
	            for(j=0;j<m;++j)
	                    ar[i][j] = str[k++];
	        }
	        else {
	            for(j=m-1;j>=0;--j)
	                    ar[i][j] = str[k++];
	        }
	    }
	    cout<<endl<<k<<"k-s "<<strSIZE<<endl;
	    for(int i=0;i<m;++i){
	        for(int j=0;j<n;++j)
	            cout<<ar[j][i];
	    }
	    cout<<endl;
	    }
    }
	return 0;
}
