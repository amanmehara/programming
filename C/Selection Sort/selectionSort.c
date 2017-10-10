#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *A, int n);

int main() {
	printf("Selection Sort \n");
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

	selectionSort(A, n);

	printf("Sorted Output \n");
	for (i = 0; i < n; i++) {
		printf("%d \n", *(A + i));
	}
	printf("\n");

	return 0;
}

void selectionSort(int *A, int n) {
	int i, j, indexOfMinimum, temp;
	for (i = 0; i < (n-1); i++) {
		indexOfMinimum = i;
		for (j = (i + 1); j < n; j++) {
			if (A[j] < A[indexOfMinimum]) {
				indexOfMinimum = j;
			}
		}
		temp = A[i];
		A[i] = A[indexOfMinimum];
		A[indexOfMinimum] = temp;
	}
}