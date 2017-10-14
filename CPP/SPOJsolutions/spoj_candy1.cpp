#include <iostream>
using namespace std;

int main() {
    int n;
    while(1){
        cin>>n;
        if(n == -1 ) break;
        else{
            int ar[n],sum=0,ret = 0;
            for(int i=0;i<n;++i){
                cin>>ar[i];
                sum+=ar[i];
            }
            int c = sum/n;
            if(sum%n !=0)   ret = -1;
            else{
                for(int i=0;i<n;++i){
                    ar[i] = ar[i]-c;
                    if(ar[i]>0) ret+=ar[i];
                }
            }
            cout<<ret<<endl;

        }
    }
	return 0;
}
