#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *A, int n);

int main() {
	printf("Insertion Sort \n");
	printf("\n");

	int i, n;

	printf("Total Elements : ");
	scanf("%d", &n);
	printf("\n");

	if (n < 1) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	int *A = (int *)calloc(n, sizeof(int));

	printf("Unsorted Input \n");
	for (i = 0; i < n; i++) {
		scanf("%d", (A + i));
	}
	printf("\n");

	insertionSort(A, n);

	printf("Sorted Output \n");
	for (i = 0; i < n; i++) {
		printf("%d \n", *(A + i));
	}
	printf("\n");

	return 0;
}

void insertionSort(int *A, int n) {
	int i, j, key;
	for (j = 1; j < n; j++) {
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i]>key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}