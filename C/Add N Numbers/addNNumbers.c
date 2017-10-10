#include <stdio.h>

int main() {
	printf("Add n Numbers \n");
	printf("\n");

	int number, n, i;
	int sum = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("\n");

	for (i = 1; i <= n; i++) {
		printf("Num %d = ", i);
		scanf("%d", &number);

		sum += number;
	}

	printf("\n");
	printf("Sum = %d \n", sum);
	printf("\n");

	return 0;
}