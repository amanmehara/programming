#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *A, int n, int key);

int main() {
	printf("Binary Search \n");
	printf("\n");

	int i, n, key, index;

	printf("Total Elements : ");
	scanf("%d", &n);
	printf("\n");

	if (n < 1) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	int *A = (int *)calloc(n, sizeof(int));

	printf("Number Input (Sorted Order)\n");
	for (i = 0; i < n; i++) {
		scanf("%d", (A + i));

		if (i > 0 && *(A + (i - 1)) > *(A + i)) {
			printf("Input Not Sorted \n");
			printf("\n");
			return 1;
		}

	}
	printf("\n");

	printf("Number to be Searched : ");
	scanf("%d", &key);
	printf("\n");

	index = binaryrec(A,0, n, key);

	printf("%d",index);

	return 0;
}

int binaryrec(int arr[] , int first , int last ,int key )
{
    int mid ;
    mid = (first + last) /2 ;
    if (arr[mid] == key )
    {
        return mid + 1;
    }
    else if(arr[mid] > key)
    {
        binaryrec(arr , first ,mid - 1 , key );
    }
    else if(arr[mid] < key)
    {
        binaryrec(arr , mid + 1 , last , key );
    }

}