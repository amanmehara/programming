#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
int d;
struct Node *next;
};
struct Node *start=NULL;

class singleLL{
    public:

void insert_end(int n){
    struct Node *temp,*s;
temp=new(Node);
temp->d=n;
temp->next=NULL;
if(start==NULL){
    start=temp;
}
else {
        s=start;
    while(s->next!=NULL){
        s=s->next;
    }
    s->next=temp;
}
}

void display(){
        struct Node *temp;
temp=start;
while(temp!=NULL){
    cout<<temp->d<<endl;
temp=temp->next;}
}


void searching(int l){
    struct Node *s;
    int v=0;
s=start;
if(s==NULL){
    cout<<"list is empty"<<endl;
    exit(0);
}
else{
while(s!=NULL){
    v++;
    if(s->d==l){
        cout<<"element found at position "<<v<<endl;
        exit(0);
    }
    else
        s=s->next;
}cout<<"element not found";}
}

int counting(){
        struct Node *temp;
temp=start;
int c=0;
singleLL sl;
if(temp==NULL){
    return c;}
else{
    while(temp!=NULL){
        c++;
    temp=temp->next;}
    return c;
}
}


void insert_begin(int n){
struct Node *temp,*s;
    temp=new(Node);
    temp->d=n;
    s=start;
    temp->next=start;
    start=temp;
}

void insert_pos(int n,int p){
    struct Node *temp,*s;
    temp=new(Node);
    int u=0;
    temp->d=n;
    if(p==1)
        insert_begin(n);
    else if(p>1&&p<=counting()){
            s=start;
        while(s!=NULL){
            u++;
            if(u==p-1)
            {
                temp->next=s->next;
                s->next=temp;
            }
            else
                s=s->next;
        }
    }
    else if(p>counting()){
        insert_end(n);
}
}
void delete_pos(int p){
 struct Node *s;
    int u=0;
    if(p==1){
        start=start->next;
    }
    else if(p>1&&p<counting()){
            s=start;
        while(s!=NULL){
            u++;
            if(u==p-1)
            {
                s->next=s->next->next;
            }
            else
                s=s->next;
        }
    }
    else if(p==counting()){
            s=start;
        while(s!=NULL){
        u++;
        if(u==p-1)
            s->next=NULL;
        else
            s=s->next;
    }}
    else if(p>counting()){
        cout<<"element not found "<<endl;
}
}

void reversing(){
	struct Node *s,*w;
	int i;
	int c=counting();
	s=start;
	w=start;
	for(i=1;i<=c-1;i++){
		s=w;
		while(s->next->next!=NULL){
			s=s->next;
		}
		s->next->next=s;
		if(i==1)
		start=s->next;
		s->next=NULL;		
	}	
	display();
}
};
int main()
{
int n,i,o=0,s,p;
int numOfNodes;
singleLL sl;
 cout<<"****MENU****"<<endl;
      cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Delete a Particular Node"<<endl;
        cout<<"5.Search Element"<<endl;
        cout<<"6.Display Linked List"<<endl;
        cout<<"7.Reverse Linked List "<<endl;
        cout<<"8. Counting number of nodes"<<endl;
        cout<<"9.Exit "<<endl;
while(o!=9){
        cout<<"enter ur option";
    cin>>o;
    switch (o){
case 1:
    cout<<"enter element";
    cin>>n;
    sl.insert_begin(n);
    sl.display();
    break;
case 2:
    cout<<"enter element";
    cin>>n;
    sl.insert_end(n);
    sl.display();
    break;
case 3:
    cout<<"enter element to be inserted and its position"<<endl;
    cin >>p>>s;
    sl.insert_pos(p,s);
    break;
case 4:
    cout<<"enter position of node i.e. to be deleted"<<endl;
    cin>>p;
    sl.delete_pos(p);
    break;
case 5:
    cout<<"enter element to be searched"<<endl;
    cin >>s;
    sl.searching(s);
    break;
case 6:
    sl.display();
    break;
case 7:
	sl.reversing();
	cout<<"done";
	
	break;
case 8:
    numOfNodes=sl.counting();
    cout<<"number of elements are "<<numOfNodes<<endl;
    break;
case 9:
    break;
    }
}
    return 0;
}
##by HARIKA S
