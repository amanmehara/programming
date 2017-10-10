#include <stdio.h>

int main() {
	printf("Greatest of 3 Numbers \n");
	printf("Ternary/Conditional Operator \n");
	printf("\n");

	int num1, num2, num3;

	printf("Num1 = ");
	scanf("%d", &num1);
	printf("Num2 = ");
	scanf("%d", &num2);
	printf("Num3 = ");
	scanf("%d", &num3);
	printf("\n");

	printf("Greatest Number = %d \n", ((num1>num2) ? num1 : num2)>num3 ? ((num1>num2) ? num1 : num2) : num3);
	printf("\n");

	return 0;
}