#include <math.h>
#include <stdio.h>

int main() {
	printf("Prime Number Checker \n");
	printf("\n");

	int number;

	printf("Enter a Natural Number (Greater than 1): \n");
	scanf("%d", &number);
	printf("\n");

	if (number < 2) {
		printf("Invalid Input \n");
		printf("\n");
		return 1;
	}

	for (int i = 2; i <= sqrt(number); i++) {
		if (!(number % i)) {
			printf("Number (%d) is Not a Prime Number \n", number);
			printf("\n");
			return 1;
		}
	}

	printf("Number (%d) is a Prime Number \n", number);
	printf("\n");

	return 0;
}