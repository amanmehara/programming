#include <stdio.h>

long recursiveFibonacci(long number);

int main() {
	long nthNumber;
	printf("nth Fibonacci : \n");
	printf("\n");

	printf("nth Number = ");
	scanf("%d",&nthNumber);
	printf("\n");

	long nthFibonacci = recursiveFibonacci(nthNumber);
	if (nthFibonacci == -1) {
		printf("Invalid Input \n");
		printf("\n");
	}
	else {
		printf("fibonacci(%d) = %d \n", nthNumber, nthFibonacci);
		printf("\n");
	}

	return 0;
}

long recursiveFibonacci(long number) {
	if (number < 0) {
		return -1;
	}
	else if (!number) {
		return 0;
	}
	else if (number == 1) {
		return 1;
	}
	else {
		return (recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2));
	}
}