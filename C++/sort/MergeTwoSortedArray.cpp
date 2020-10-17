#include <iostream>
using namespace std;
void merge(int fi[],int se[],int u1, int v1);//declared merge function
//main function
int main() {

//input of array
    int f[]={11,16,21,45};
    int s[]={6,8,8,11,16};
   int s1=sizeof(f)/sizeof(f[0]);
    int s2=sizeof(s)/sizeof(s[0]);
	merge(f,s,s1,s2);
	return 0;
}
//merge function
void merge(int fi[],int se[],int u1, int v1)
{
 int i=0;
 int j=0;
 while(i<u1&&j<v1)
  {
   if(fi[i]<se[j])
    {
        cout<<fi[i++]<<" ";
    }
    else
      {
          cout<<se[j++]<<" ";
      }
 
  }
 while(i<u1){cout<<fi[i++]<<" "; }
  while(j<v1){cout<<se[j++]<<" "; }
}
