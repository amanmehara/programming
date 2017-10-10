#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int *A, int i, int n);
void buildMaxHeap(int *A, int n);
void heapSort(int *A, int n);

int main() {
	printf("Heap Sort \n");
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

	heapSort(A, (n-1));

	printf("Sorted Output \n");
	for (i = 0; i < n; i++) {
		printf("%d \n", *(A + i));
	}
	printf("\n");

	return 0;
}

void maxHeapify(int *A, int i, int n) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest, temp;
	if (left <= n && *(A + left) > *(A + i)) {
		largest = left;
	}
	else {
		largest = i;
	}

	if (right <= n && *(A + right) > *(A + largest)) {
		largest = right;
	}

	if (largest != i) {

		//swap
		temp = *(A + i);
		*(A + i) = *(A + largest);
		*(A + largest) = temp;

		maxHeapify(A, largest, n);
	}
}

void buildMaxHeap(int *A, int n) {
	for (int i = n / 2; i >= 0; i--) {
		maxHeapify(A, i, n);
	}
}

void heapSort(int *A, int n) {
	int length = n;
	int temp;
	buildMaxHeap(A, n);
	for (int i = length; i > 0; i--) {

		//swap
		temp = *(A);
		*(A) = *(A + i);
		*(A + i) = temp;

		n--;
		maxHeapify(A, 0, n);
	}
}