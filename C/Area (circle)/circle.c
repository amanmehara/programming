#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main() {
	printf("Area : Circle \n");
	printf("\n");

	double radius;

	printf("radius = ");
	scanf("%lf", &radius);
	printf("\n");

	printf("Area = %lf \n", PI*pow(radius, 2));
	printf("\n");

	return 0;
}