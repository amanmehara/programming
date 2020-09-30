//Contributed by Akshad Kolhatkar [github.com/AkshadK7]

//Implementing An Iterative Program to accept List values from user and Swap the List elements

#include<iostream>
#include<malloc.h>
using namespace std;

/* Link list node */
void Create();
struct Node
{
  int data;
  struct Node *link;
}*start;


//Driver Program
int main()
{
  int n,i,X,Y;
  int flag=0;
  start=NULL;
  cin>>n;

  //Accepting User Values
  for(i=0;i<n;i++)
  {
    Create();
  }
  cin>>X;
  cin>>Y;
  struct Node *t;
  t=start;
  while(t!=NULL)
  {
    if((t->data==X) &&(t->link->data==Y))
    {
      flag=1;
      break;
    }
    t=t->link;
  }
  if(flag==1)
  {
    
   t=start;
    cout<<"Linked list before Swapping :";
   
   while(t!=NULL)
    {
     cout<<"->"<<t->data;
 	t=t->link;
    }
    
 
    t=start;
    cout<<endl<<"Linked list after Swapping :";
  while(t!=NULL)
  {
    if(t->data==X)
    {
      t->data=Y;
    }
    else if(t->data==Y)
    {
      t->data=X;
    }
    cout<<"->"<<t->data;
 t=t->link;
  }
  }
  else
  {
    cout<<"Invalid Node! \n";
   cout<<"Linked list before Swapping : ";
   t=start;
  while(t!=NULL)
  {
    cout<<"-->"<<t->data;
 t=t->link;
  }
  cout<<endl<<"Linked list after Swapping : ";
   t=start;
  while(t!=NULL)
  {
    cout<<"-->"<<t->data;
 t=t->link;
  }  
  }
  return 0;
}


/* Creating New Nodes */
void Create()
{
  struct Node *temp,*t;
  temp=(struct Node*) malloc(sizeof(struct Node));
  cin>>temp->data;
  temp->link=NULL;
  if(start==NULL)
  {
    start=temp;
  }
  else
  {
    t=start;
    while(t->link!=NULL)
     t=t->link;
    t->link=temp;
  }
}