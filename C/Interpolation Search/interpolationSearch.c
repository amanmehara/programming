#include <stdio.h>
#include <stdlib.h>

int interpolationSearch(int *A, int n, int key);

int main() {
	printf("Interpolation Search \n");
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

	index = interpolationSearch(A, n, key);

	if (index == -1) {
		printf("Number (%d) not found \n", key);
	}
	else {
		printf("Number (%d) found at Index : %d \n", key, index);
	}

	printf("\n");

	return 0;
}

int interpolationSearch(int *A, int n, int key) {
	int p = 0, q, r = (n - 1);

	while (p < r) {
		q = p + (r - p)*((key - *(A + p)) / (*(A + r) - *(A + p)));

		if (key == *(A + q)) {
			return q;
		}
		else if (key > *(A + q)) {
			p = q + 1;
		}
		else {
			r = q - 1;
		}
	}

	return -1;
}