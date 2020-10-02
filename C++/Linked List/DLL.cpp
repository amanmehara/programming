#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
int d;
struct Node *next;
struct Node *prev;
};
struct Node *start=NULL;

class doubleLL{
    public:

void insert_end(int n){
    struct Node *temp,*s;
temp=new(Node);
temp->d=n;
temp->next=NULL;
if(start==NULL){
    start=temp;
    temp->prev=NULL;
}
else {
        s=start;
    while(s->next!=NULL){
        s=s->next;
    }
    s->next=temp;
    temp->prev=s;
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
doubleLL sl;
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
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL){
    	start=temp;
	}
	else{
	temp->next=start;
	s->prev=temp;
	start=temp;	
	}
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
                temp->prev=s;
                s->next=temp;
                temp->next->prev=temp;
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
        start->prev=NULL;
    }
    else if(p>1&&p<counting()){
            s=start;
        while(s!=NULL){
            u++;
            if(u==p-1)
            {
                s->next=s->next->next;
                s->next->next->prev=s;
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

void delete_val(int n){
	struct Node *s;
	s=start;
	int y=1;
	while(s!=NULL){
	
		if(s->d==n){
			delete_pos(y);
			cout<<"done";
		}
		s=s->next;
			y++;
	}
}
};
int main()
{
int n,i,o=0,s,p;
int numOfNodes;
doubleLL dl;
 cout<<"****MENU****"<<endl;
      cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Delete a Particular Node"<<endl;
        cout<<"5.Search Element"<<endl;
        cout<<"6.Display Linked List"<<endl;
        cout<<"7.Delete a node by its value "<<endl;
        cout<<"8. Counting number of nodes"<<endl;
        cout<<"9.Exit "<<endl;
while(o!=9){
        cout<<"enter ur option";
    cin>>o;
    switch (o){
case 1:
    cout<<"enter element";
    cin>>n;
    dl.insert_begin(n);
    dl.display();
    break;
case 2:
    cout<<"enter element";
    cin>>n;
    dl.insert_end(n);
    dl.display();
    break;
case 3:
    cout<<"enter element to be inserted and its position"<<endl;
    cin >>p>>s;
    dl.insert_pos(p,s);
    break;
case 4:
    cout<<"enter position of node i.e. to be deleted"<<endl;
    cin>>p;
    dl.delete_pos(p);
    break;
case 5:
    cout<<"enter element to be searched"<<endl;
    cin >>s;
    dl.searching(s);
    break;
case 6:
    dl.display();
    break;
case 7:
	cout<<"enter element";
	cin>>n;
	dl.delete_val(n);
	break;
case 8:
    numOfNodes=dl.counting();
    cout<<"number of elements are "<<numOfNodes<<endl;
    break;
case 9:
    break;
    }
}
    return 0;
}
##by HARIKA S
