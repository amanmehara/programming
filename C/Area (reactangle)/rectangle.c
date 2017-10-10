#include <stdio.h>

int main() {
	printf("Area : Rectangle \n");
	printf("\n");

	double length, breadth;

	printf("length = ");
	scanf("%lf", &length);
	printf("breadth = ");
	scanf("%lf", &breadth);
	printf("\n");

	printf("Area = %lf \n", length*breadth);
	printf("\n");

	return 0;
}