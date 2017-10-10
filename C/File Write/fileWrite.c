#include <stdio.h>

int main() {
	FILE *filePointer;
	char character;

	printf("File Write\n");
	printf("\n");

	if ((filePointer = fopen("test.txt", "w")) == NULL) {
		perror("test.txt");
		return 1;
	}

	printf("Writing to test.txt: \n");
	printf("(^@ to exit) \n");
	printf("\n");

	while (true) {
		scanf("%c", &character);
		if (character == NULL) {
			break;
		}
		character = fputc(character, filePointer);
	}
	printf("\n");
	printf("\n");

	fclose(filePointer);

	return 0;
}