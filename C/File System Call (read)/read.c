#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int fd, i;
	char buffer[100];

	if (argc != 2) {
		printf("Number of Arguements provided != 2 \n");
		printf("Arguements Required: \n");
		printf("Filename \n");
		exit(-1);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		perror(argv[1]);
		exit(-1);
	}

	printf("%s : \n", argv[1]);
	printf("\n");

	while (read(fd, buffer, sizeof(buf)) > 0) {
		printf("%s", buffer);
	}

	close(fd);

	printf("\n");

	return 0;
}