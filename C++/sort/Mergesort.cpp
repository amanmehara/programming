# Merge Sort is a kind of Divide and Conquer algorithm in computer programming. It is one of the most popular sorting algorithms and a great way to develop confidence in building recursive algorithms.

#include<iostream>
using namespace std;
int Merge(int A,int L,int R,)
{
  int i=0;
  int j=0;
  int k=0;
  while(i<L.length() && j<R.length())
  {
    if(L[i]<=R[i])
    {
      A[k]=L[i];
      i=i+1;
      k=k+1;
    }
    else
    {
      A[k]=R[j];
      j=j+1;
      k=k+1;
    }
  }
  while(i<L.length())
  {
    A[k]=L[i];
    i=i+1;
    k=k+1;
  }
  while(j<R.length())
  {
    A[k]=R[j];
    j=j+1;
    k=k+1;
}

void MergeSort(A)
{
  int n=A.length();
  if(n<2)
  {
    return;
  }
  int mid=n/2;
  for(i=0;i<mid-1;i++)
  {
    L[i]=A[i];
  }
  for(i=mid;i<n-1;i++)
  {
    R[i-mid]=A[i];
  }
  MergeSort(L);
  MergeSort(R);
  Merge(L,R,A);
}

int main()
{
int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];
 
	return 0;
}
}
