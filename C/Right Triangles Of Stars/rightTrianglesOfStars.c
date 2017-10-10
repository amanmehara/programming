#include <stdio.h>

int main()
{
	int height;
	printf("Right Triangle of * \n");
	printf("\n");
	printf("Maximum Permissible Height = 40 \n");
	printf("Height of Triangle = ");
	scanf("%d", &height);
	printf("\n");

	if (height > 40) {
		fprintf(stderr, "Height > 40 \nAborting! \n");
		return -1;
	}

	int i, j;
	for (i = 1; i <= height; i++) {
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}