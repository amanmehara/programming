#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r);
void quickSort(int *A, int p, int r);

int main() {
	printf("Quick Sort \n");
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

	quickSort(A, 0, (n - 1));

	printf("Sorted Output \n");
	for (i = 0; i < n; i++) {
		printf("%d \n", *(A + i));
	}
	printf("\n");

	return 0;
}

int partition(int *A, int p, int r) {
	int x = *(A + r);
	int i = p - 1;
	int temp;
	for (int j = p; j < r; j++) {
		if (*(A + j) <= x) {
			i++;

			//swap
			temp = *(A + i);
			*(A + i) = *(A + j);
			*(A + j) = temp;
		}
	}

	//swap
	temp = *(A + (i + 1));
	*(A + (i + 1)) = *(A + r);
	*(A + r) = temp;

	return i + 1;
}

void quickSort(int *A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, (q - 1));
		quickSort(A, (q + 1), r);
	}
}