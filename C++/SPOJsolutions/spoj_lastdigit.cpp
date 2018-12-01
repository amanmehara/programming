#include <iostream>
#include <math.h>
using namespace std;
///last digit pattern always stays inside 4 nos
//google codechef last digit
int main() {
int t;
cin>>t;
while(t--){
    int a,ret=1,rem;
    long long b;
    cin>>a>>b;
    if(b==0) ret = 1;
    else{
        rem=b%4;
        if(rem==0)  rem = 4;
        while(rem--){
            ret = (ret*a)%10;
        }
    }

    cout<<ret<<endl;
}
return 0;
}
