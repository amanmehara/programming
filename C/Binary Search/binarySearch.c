#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *A, int n, int key);

int main() {
	printf("Binary Search \n");
	printf("\n");

	int numberOfElement, key, index;

	printf("Total Elements : ");
	scanf("%d", &numberOfElement);
	printf("\n");

	if (numberOfElement < 1) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	int *A = (int *)calloc(numberOfElement, sizeof(int));

	printf("Number Input (Sorted Order)\n");
	for (int i = 0; i < numberOfElement; i++) {
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

	index = binarySearch(A, numberOfElement, key);

	if (index == -1) {
		printf("Number (%d) not found \n", key);
	}
	else {
		printf("Number (%d) found at Index : %d \n", key, index);
	}

	printf("\n");

	return 0;
}

int binarySearch(int *A, int size, int key) {
	int left = 0, mid, right = (size-1);

	while (left <= right) {
		mid = (left + right) / 2;

		if (key == *(A + mid)) {
			return mid;
		}
		else if (key > *(A + mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}