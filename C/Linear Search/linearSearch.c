#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *A, int n, int key);

int main() {
	printf("Linear Search \n");
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

	printf("Number Input \n");
	for (i = 0; i < n; i++) {
		scanf("%d", (A + i));
	}
	printf("\n");

	printf("Number to be Searched : ");
	scanf("%d", &key);
	printf("\n");

	index = linearSearch(A, n, key);

	if (index == -1) {
		printf("Number (%d) not found \n", key);
	}
	else {
		printf("Number (%d) found at Index : %d \n", key, index);
	}

	printf("\n");

	return 0;
}

int linearSearch(int *A, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (*(A + i) == key) {
			return i;
		}
	}
	return -1;
}