#include <bits/stdc++.h>
using namespace std;

int calc ( vector <int> &v )
{
    sort (v.begin(), v.end());
    int mx=0;
    for (int i=0 ; i+1<v.size(); i++)
    {
        mx=max((v[i+1]-v[i])-1, mx);
    }
    return mx;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--)
    {

        vector <int >  rows, col ;
        int R, C, n;
        cin >> R>> C >> n;
        for (int i = 0; i < n; ++i)
        {
            int r, c;
            cin >> r>> c;
            r--;
            c--;
            rows.push_back(r);
            col.push_back(c);

        }
        rows.push_back(-1);
        col.push_back(-1);
        rows.push_back(R);
        col.push_back(C);

        int res= calc(rows)*calc(col);

        cout<<res<<endl;



    }

    return 0;

}