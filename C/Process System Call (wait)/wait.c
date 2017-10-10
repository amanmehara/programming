#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int i, status;
	pid_t pid;
	pid = fork();

	if (pid == -1) {
		printf("Process Creation Error. \n");
		exit(-1);
	}

	else if (pid > 0) {
		wait(NULL);
		printf("Parent Starts: \n");
		printf("Even Numbers: \n");

		for (i = 0; i <= 10; i++) {
			if (!(i % 2)) {
				printf("%d \n", i);
			}
		}

		printf("Parent Ends. \n");
		printf("\n");
	}

	else {
		printf("Child Starts: \n");
		printf("Odd Numbers: \n");

		for (i = 0; i <= 10; i++) {
			if (i % 2) {
				printf("%d \n", i);
			}
		}

		printf("Child Ends. \n");
		printf("\n");
	}

	return 0;
}