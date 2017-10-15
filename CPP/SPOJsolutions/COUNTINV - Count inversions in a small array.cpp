/// modification of merge_sort to count inversions of a array

#include <iostream>
#include <stdio.h>
using namespace std;

typedef long typ;
typedef long long siz;
/*const siz SIZE_OF_HASH = 1000001;
// DISPLAY hasing Function //
typ hasher[SIZE_OF_HASH];

void display_hsh(typ lis[], siz n){
	for (siz i=0 ; i<n ; ++i)
		    printf("%ld ",hasher[lis[i]]);
	cout<<endl;								// newline at end
}

void init_hash(){
	for(siz i=0;i<SIZE_OF_HASH;++i){
		hasher[i] = 0;
	}
}
siz count_inversion(typ lis[], siz n){
	siz inv = 0;
	for (siz i=0 ; i<n ; ++i)
		inv+=hasher[lis[i]];
	return inv;								// newline at end
}
* 
* */

///*
// MERGE SORT //
 
///https://en.wikipedia.org/wiki/Inversion_%28discrete_mathematics%29
//part1 and part2 vedio for analysis of this approach!
///https://www.youtube.com/watch?v=yP0asUjcrBA
///https://www.youtube.com/watch?v=hqeoAIryJOc

// *count inversion and merge function* //
siz countinv = 0;
void count_invertion_merge_it(typ lis1[],typ lis2[],typ lis[], siz n1, siz n2, siz n){			//last arg can be removed as it n1+n2
	siz p=0,q=0,r=0,counter=0;
	while(p<n1 && q<n2){				// while both index are les than array sizes
		if(lis1[p] <= lis2[q]){			// merge in ascending ordrer
			//hasher[lis1[p]]+=counter;
			countinv += counter;
			lis[r++] = lis1[p++];
			
		}
		else{
			//for(siz k=p;k<n1;++k)
			    //hasher[lis1[p]]++;		//ONLY CHANGE MADE IN MERGESORT
				counter++;			// hashing is used to identify the counter!
			lis[r++] = lis2[q++];
		}
	}
	while(p<n1){
	    //hasher[lis1[p]]+=counter;						// one finised then coppy the others which left
	    countinv += counter;
	    lis[r++] = lis1[p++];
		
	}
	while(q<n2){
		lis[r++] = lis2[q++];
	}
	//display(lis,n);					//display all the partitions bottom-up ... give a good look at the algo
}


// *traditional Merge_Sort function that calls the count_invertion_merge_it function* //
//NO CHANGE
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
		count_invertion_merge_it(lis1,lis2,lis,pos,n-pos,n);		// merge it will create the whole array again bottom-up
	}
}
///document and write the modifications made and the issues learnt

// no hasher is used as neg input is present
int main(){
	//typ Ar[] = {5 ,2 ,10 ,8 ,1 ,9 ,4 ,3 ,6 ,7};
	//typ Br[] = {3,1,6,5,2,4};
	//siz size = (sizeof(Ar)/sizeof(Ar[0]));
	//cout<<size<<endl;
	int n;
	cin>>n;
	while(n != 0){
		countinv = 0;
		//init_hash();
		typ Ar[n];
		for(siz i=0; i<n; ++i)
			cin>>Ar[i];
		merge_sort(Ar,n);
		//display_hsh(Br,size);
		cout<<countinv<<endl;
		cin>>n;	
	}
return 0;
}





