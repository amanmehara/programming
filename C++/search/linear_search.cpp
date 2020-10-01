#include<bits/stdc++.h>
using namespace std;

int search(vector<int> v, int find)
{
	int l= v.size();
	for(int i=0; i<l ; i++)
	{
		if(find==v[i])
			return i;
	}
	//if not found in the array
	return -1;
}

int main()
{
	vector<int> v;
	//array for example is: 1 3 5 2 4 6 7 9 8
	v.push_back(1);v.push_back(3);v.push_back(5);
	v.push_back(2);v.push_back(4);v.push_back(6);
	v.push_back(7);v.push_back(9);v.push_back(8);
	
	int n;
	//to search this element
	cin>>n;
	
	int l= search(v,n);
	if(l==-1)
		cout<<"Not found\n";
	else
		cout<<n<<" is found at position "<<l<<endl;
		
	return 0;
}
