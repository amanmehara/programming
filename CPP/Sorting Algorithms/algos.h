//Fatima Mubeen
//Sorting algos Header file with source file  Source.cpp
#include<iostream>
#include<conio.h>
using namespace std;
class sort{
	int *arr,size;
public:
	sort(){
		arr = NULL;
		size = 0;
	}
	sort(int *&a, int s){
		arr = a;
		size = s;
	}
	void setArray(int *&a,int s){

		arr = a;
	}
	void setSize(int s){
		size = s;
	}
	int* getArray(){
		return arr;
	}
	int getSize(){
		return size;
	}
	void printArray(){
		cout << endl << "Array is :  ";
		for (int i = 0; i < size; i++){
			cout << arr[i] << " ";
		}
	}
	void bubbleSort(){
		for (int i = 0; i < size; i++)
		{
			int t = 0;
			for (int j = 1; j < size - i; j++)
			{
				if (arr[j - 1]>arr[j])
				{
					t = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = t;
				}
			}
		}
	}
	void selectionSort(){
		int min, minIndex;
		for (int i = 0; i <size; i++)
		{
			min = arr[i]; minIndex = i;
			for (int j = i + 1; j < size ; j++)
			{
				if (arr[j] < min)
				{
					min = arr[j]; minIndex = j;
				}
			}
			arr[minIndex] = arr[i];
			arr[i] = min;
		}
	}
	void insertionSort(){
		int i, j , t;
		for (i = 1; i < size; i++)
		{
			t = arr[i];
			for (j = 0; j < i; ++j) 
			{
				if (t < arr[j])  
					break;
			}
			for (int m = i; m>j; m--) 
			{
				arr[m] = arr[m - 1]; 
			}
			arr[j] = t;
		}
	}

};
