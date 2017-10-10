#include <stdio.h>
#include <math.h>

int main() {
	printf("Area : Square \n");
	printf("\n");

	double side;

	printf("side = ");
	scanf("%lf", &side);
	printf("\n");

	printf("Area = %lf \n", pow(side, 2));
	printf("\n");

	return 0;
}