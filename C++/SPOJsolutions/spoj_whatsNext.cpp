#include <iostream>

using namespace std;
int main() {
    int n,m,p;
    while(1){
        cin>>n>>m>>p;
        if ((n==0) && (m==0) && (p==0))
            break;
        if(m-n == p-m){
            cout<<"AP "<<p+(p-m)<<endl;
        }
        else if(m/n == p/m){
            cout<<"GP "<<p*(p/m)<<endl;
        }

    }
	return 0;
}


