#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int box,screw,table,temp;
	cin>>box>>screw>>table;
	screw = screw*table;
	vector<int> scr;
	while(box--){
		cin>>temp;
		scr.push_back(temp);
	}
	sort(scr.begin(),scr.end());
	reverse(scr.begin(),scr.end());
	//cout<<scr[0]<<scr[1]<<scr[2]<<scr[3]<<scr[4]<<endl;
	int count=1,max=scr[0];
	while(1){
		if(max>=screw)	break;
		else max+=scr[count++];
		//count++;
		//cout<<max<<endl;
	}
	cout<<count<<endl;
	return 0;
}
