#include <stdio.h>
#include <math.h>

int main() {
	printf("Quadratic Equation \n");
	printf("( ax%c + bx + c = 0 ) \n", 253);
	printf("\n");

	float a, b, c, alpha, beta, discriminant;

	printf("a = ");
	scanf("%f", &a);
	printf("b = ");
	scanf("%f", &b);
	printf("c = ");
	scanf("%f", &c);
	printf("\n");

	if (!a) {
		printf("\'a\' must not be 0. \n");
	}
	else {
		discriminant = pow(b, 2) - 4 * a*c;
		printf("Discriminant : %f \n", discriminant);
		printf("\n");

		if (discriminant > 0) {
			alpha = (-b + sqrt(discriminant)) / (2 * a);
			beta = (-b - sqrt(discriminant)) / (2 * a);

			printf("The roots are Real and Distinct \n");
			printf("\n");

			printf("alpha = %f \n", alpha);
			printf("beta = %f \n", beta);
			printf("\n");
		}
		else if (!discriminant) {
			alpha = beta = -b / (2 * a);

			printf("The roots are Real and Equal \n");
			printf("\n");

			printf("alpha = beta = %f \n", alpha);
			printf("\n");
		}
		else {

			printf("Root are Complex (Real + Imaginary) \n");
			printf("\n");

			printf("alpha = %f + %f i \n", (-b / (2 * a)), sqrt(fabs(discriminant)) / (2 * a));
			printf("beta = %f - %f i \n", (-b / (2 * a)), sqrt(fabs(discriminant)) / (2 * a));
			printf("\n");
		}
	}

	return 0;
}