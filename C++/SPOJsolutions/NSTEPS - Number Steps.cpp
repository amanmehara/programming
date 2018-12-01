#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
	bool flag = false;
	int x,y;
	cin>>x>>y;
	if(x<0 || y<0) flag = false;
	else if(x==y){
	    flag = true;
	    if(x%2 != 0)
		cout<<2*x-1;
	    else{
		cout<<2*x;
	    }
	}
	else if(x == y+2){
	    flag = true;
	    if(x%2 != 0)
		cout<<2*(x-1)-1;
	    else{
		cout<<2*(x-1);
	    }
	}
    if (!flag) cout<<"No Number";
    cout<<endl;
    
    }
return 0;
}
