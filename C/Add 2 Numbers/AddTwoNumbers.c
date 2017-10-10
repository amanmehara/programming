#include <stdio.h>

int main() {
	printf("Add 2 Numbers \n");
	printf("\n");

	int num1, num2;

	printf("Num1 = ");
	scanf("%d", &num1);
	printf("Num2 = ");
	scanf("%d", &num2);
	printf("\n");

	printf("%d + %d = %d \n", num1, num2, num1 + num2);
	printf("\n");

	return 0;
}