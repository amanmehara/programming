#include <stdio.h>

int main() {
	FILE *filePointer;
	char character;

	printf("File Read\n");
	printf("\n");

	if ((filePointer = fopen("test.txt", "r")) == NULL) {
		perror("test.txt");
		return 1;
	}

	printf("test.txt contains: \n");
	printf("\n");

	while (true) {
		character = fgetc(filePointer);
		if (character == EOF) {
			break;
		}
		printf("%c", character);
	}
	printf("\n");
	printf("\n");

	fclose(filePointer);

	return 0;
}