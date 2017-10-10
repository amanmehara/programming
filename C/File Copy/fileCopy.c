#include <stdio.h>

int main() {
	FILE *fileReadPointer, *fileWritePointer;
	char character;

	printf("File Copy\n");
	printf("\n");

	if ((fileReadPointer = fopen("input.txt", "r")) == NULL) {
		perror("input.txt");
		return 1;
	}

	if ((fileWritePointer = fopen("output.txt", "w")) == NULL) {
		perror("output.txt");
		return 1;
	}

	printf("Copying contents of input.txt to output.txt \n");
	printf("\n");

	while (true) {
		character = fgetc(fileReadPointer);
		if (character == EOF) {
			break;
		}
		else {
			fputc(character, fileWritePointer);
		}
	}
	printf("Successfully Copied \n");
	printf("\n");

	fclose(fileReadPointer);
	fclose(fileWritePointer);

	return 0;
}