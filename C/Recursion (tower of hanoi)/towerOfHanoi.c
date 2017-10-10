#include <stdio.h>

void recursiveTowerOfHanoi(int numberOfDisks, char Source, char Destination, char Intermediate);

int main() {
	int numberOfDisks;

	printf("Tower of Hanoi \n");
	printf("\n");

	printf("S = Source tower \nI = Intermediate tower \nD = Destination tower \n");
	printf("\n");

	printf("Total Disks in Source tower = ");
	scanf("%d", &numberOfDisks);
	printf("\n");

	printf("Solution (with minimum number of moves): \n");
	printf("\n");

	recursiveTowerOfHanoi(numberOfDisks, 'S', 'D', 'I');
	printf("\n");

	return 0;
}

void recursiveTowerOfHanoi(int numberOfDisks, char Source, char Destination, char Intermediate) {
	if (numberOfDisks) {
		recursiveTowerOfHanoi((numberOfDisks - 1), Source, Destination, Intermediate);
		printf("Disk %d moved from %c to %c \n", numberOfDisks, Source, Destination);
		recursiveTowerOfHanoi((numberOfDisks - 1), Intermediate, Destination, Source);
	}
}