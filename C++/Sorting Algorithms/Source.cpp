//Fatima Mubeen
//Sorting algos Source file (its header file is algos.h)
#include<iostream>
#include<conio.h>
#include"algos.h"
using namespace std;
void main(){
	int *a, s;
	cout << "Enter Size of Array :";
	cin >> s;
	a = new int[s];
	cout << "Enter Array Elements : ";
	for (int i = 0; i < s; i++){
		cout <<"Element "<<i+1<<" : ";
		cin >> a[i];
	}
	sort SORT(a, s);
	cout << "Before Sorting ";
	SORT.printArray();
	cout << endl<< "After Sorting ";
	//SORT.bubbleSort();					//you can call any sorting algo here I have called inserstion and commented others
	//SORT.selectionSort();
	SORT.insertionSort();
	SORT.printArray();

	_getch();

}