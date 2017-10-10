#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
	pid_t pid;
	int i;

	if (argc != 3) {
		printf("Number of Arguements provided != 3 \n");
		printf("Arguements Required: \n");
		printf("Path \n");
		printf("Command \n");
		exit(-1);
	}

	switch (pid = fork()) {
	case -1:
		printf("Process Creation Error. \n");
		exit(-1);

	case 0:
		printf("Child Starts :\n");

		if (execl(argv[1], argv[2], 0) < 0) {
			perror(argv[2]);
			exit(-1);
		}

		break;

	default:
		wait(NULL);
		printf("Child Terminated. \n");
	}

	printf("\n");

	return 0;
}