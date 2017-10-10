#include <stdio.h>

int main() {
	printf("Simple Interest & Amount \n");
	printf("\n");

	float principal, rate, simpleInterest, amount;
	int time;

	printf("Principal \t: ");
	scanf("%f", &principal);
	printf("Interest Rate \t: ");
	scanf("%f", &rate);
	printf("Time (yrs) \t: ");
	scanf("%d", &time);
	printf("\n");

	printf("\n");

	printf("Simple Interest = (Principal * Rate * Time) / 100 \n");
	simpleInterest = (principal*rate*time) / 100;
	printf("Simple Interest = %.2f \n", simpleInterest);
	printf("\n");

	printf("Total Amount = Principal + Simple Interest \n");
	amount = principal + simpleInterest;
	printf("Total Amount = %.2f \n", amount);
	printf("\n");

	return 0;
}