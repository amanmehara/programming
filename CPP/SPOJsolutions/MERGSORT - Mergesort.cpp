#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long typ;
typedef long siz;

// DISPLAY Function //

void display(typ lis[], siz n){
	for (siz i=0 ; i<n ; ++i)
		cout<<lis[i]<<" ";
	cout<<endl;								// newline at end
}


// MERGE SORT //
 
///https://en.wikipedia.org/wiki/Merge_sort

// *merging function* //
void merge_it(typ lis1[],typ lis2[],typ lis[], siz n1, siz n2, siz n){			//last arg can be removed as it n1+n2
	siz p=0,q=0,r=0;
	while(p<n1 && q<n2){				// while both index are les than array sizes
		if(lis1[p] <= lis2[q])			// merge in ascending ordrer
			lis[r++] = lis1[p++];		
		else
			lis[r++] = lis2[q++];
	}
	while(p<n1){						// one finised then coppy the others which left
		lis[r++] = lis1[p++];
	}
	while(q<n2){
		lis[r++] = lis2[q++];
	}
	//display(lis,n);					//display all the partitions bottom-up ... give a good look at the algo
}


// *merge sort function that calls the merge_it function* //
void merge_sort(typ lis[], siz n){
	if(n>1){							// exit condition if array size is 1, ie- already sorted
		siz pos = n/2;					// divide it in half (possible half)
		siz k = 0;
		typ lis1[pos],lis2[n-pos];		// create two arrays of possible half size
		for(siz i=0;i<pos;++i){
			lis1[i] = lis[k++];			//coppy elements
		}
		for(siz i=0;i<n-pos;++i){
			lis2[i] = lis[k++];			// ..
		}
		merge_sort(lis1,pos);			// recursive call to merge_sort with the left part, so all the left part will do its ork and
		merge_sort(lis2,n-pos);			// then right side and then the last recursion will call merge_it
		merge_it(lis1,lis2,lis,pos,n-pos,n);		// merge it will create the whole array again bottom-up
	}
}



int main(){
	typ Ar[100001];
	siz i = 0;
	typ n;
	while(scanf("%lld",&n) != EOF){			///great tip to learn!
		Ar[i++] = n;
	}
	//siz size = (sizeof(Ar)/sizeof(Ar[0]));
	merge_sort(Ar,i);
	display(Ar,i);
return 0;
}
