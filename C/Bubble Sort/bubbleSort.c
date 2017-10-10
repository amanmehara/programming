#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *A, int n);

int main() {
	printf("Bubble Sort \n");
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

	bubbleSort(A, n);

	printf("Sorted Output \n");
	for (i = 0; i < n; i++) {
		printf("%d \n", *(A + i));
	}
	printf("\n");

	return 0;
}

void bubbleSort(int *A, int n) {
	bool isSwapped;
	int i, temp;
	do {
		isSwapped = false;
		for (i = 0; i < n; i++) {
			if (A[i - 1] > A[i]) {
				temp = A[i - 1];
				A[i - 1] = A[i];
				A[i] = temp;
				isSwapped = true;
			}
		}
	} while (isSwapped);
}