#include<bits/stdc++.h>
using namespace std;
int y;
struct Queue{
    stack<int> s1,s2;

void enqueue(int x){
    s1.push(x);
}

int dequeue(){
    if (s1.empty() && s2.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        }
if(s2.empty()){

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
}
    y=s2.top();
    s2.pop();
    return y;

}
};
int main() {
    cout<<"enqueue operation O(1) and dequeue O(n)";
	Queue q;
	int o=0,p,n;

while(o!=3){
        cout<<"enter your choice";
	cin>>o;
    	switch(o){
	case 1:
	    {
	        cout<<"enter element to enqueue";
	    cin>>n;
	    q.enqueue(n);
	    break;
	    }
	case 2:
        {
            p=q.dequeue();
        cout<<p<<endl;
        break;
        }
    case 3:
        break;
	}
}
	return 0;
}
