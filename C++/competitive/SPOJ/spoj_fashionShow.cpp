#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        long sum=0;
        cin>>n;
        int men[n],wom[n];
        for(int i=0;i<n;++i)
            cin>>men[i];
        for(int i=0;i<n;++i)
            cin>>wom[i];
        sort(men,men+n);
        sort(wom,wom+n);
        for(int i=0;i<n;++i)
            sum+=men[i]*wom[i];
        cout<<sum<<endl;
    }
return 0;
}
