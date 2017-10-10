#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fd, n, length;
	char buffer[100];

	if (argc != 2) {
		printf("Number of Arguements provided != 2 \n");
		printf("Arguements Required: \n");
		printf("Filename \n");
		exit(-1);
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd < 0) {
		perror(argv[1]);
		exit(-1);
	}

	printf("Use Ctrl-D in a New Line to Exit! \n");
	printf("\n");

	while ((n = read(0, buffer, sizeof(buffer))) > 0) {
		length = strlen(buffer);
		write(fd, buffer, length);
	}

	close(fd);

	printf("\n");

	return 0;
}