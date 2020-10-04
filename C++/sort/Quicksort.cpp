# Quicksort is an algorithm based on divide and conquer approach in which the array is split into subarrays and these sub-arrays are recursively called to sort the elements.

#include<iostream>
using namespace std;
int partition(int *A, int start, int end)
{
  int pivot=A[end];
  int partitionIndex=start;
  for(int i=start;i<end;i++)
  {
    if(A[i]<=pivot)
    {
      swap(A[i],A[partitionIndex]);
      partitionIndex++;
    }
  }
  swap(A[partitionIndex],A[end]);
  return partitionIndex;
}
void Quicksort(int *A, int start, int end)
{
  if(start<end)
  {
    int partitionIndex=partition(A,start,end);
    Quicksort(A,start,partitionIndex-1);
    Quicksort(A,partitionIndex+1,end);
  }
}
int main()
{
  int i,n,A[20];
  cout<<"Enter size of the array: ";
  cin>>n;
  cout<<"Enter elements for the array: \n";
  for(i=0;i<n;i++)
  {
    cin>>A[i];
  }
  Quicksort(A,0,n-1);
  for(i=0;i<n;i++)
  {
    cout<<A[i]<<" ";
  }
}
