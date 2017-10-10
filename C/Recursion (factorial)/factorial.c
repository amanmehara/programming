#include <stdio.h>

long int recursiveFactorial(long int input);

int main() {
	long int number, result;

	printf("Factorial of a number: \n");
	printf("\n");

	printf("Enter a Whole Number (max. 12): \n");
	scanf("%ld",&number);
	printf("\n");

	if (number > 12) {
		printf("Number > 12 \n");
		printf("\n");
		return 1;
	}

	result = recursiveFactorial(number);

	if (result == -1) {
		printf("Invalid Input \n");
	}
	else {
		printf("(%ld)! = %ld \n", number, result);
	}
	printf("\n");

	return 0;
}

long int recursiveFactorial(long int input)
{
	if (input < 0) {
		return -1;
	}

	return (input ? (input*recursiveFactorial(input - 1)) : 1);
}