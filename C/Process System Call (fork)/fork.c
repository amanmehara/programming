#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int x = 5;
	pid = fork();
	x++;

	if (pid == -1) {
		printf("Process Creation Error. \n");
		exit(-1);
	}

	else if (!pid) {
		printf("Child Process : \n");
		printf("Process ID (Child) is %d \n", getpid());
		printf("Value of x is %d \n", x);
		printf("Process ID of Parent is %d \n", getppid());
	}

	else {
		printf("Parent Process : \n");
		printf("Process ID (Parent) is %d \n", getpid());
		printf("Value of x is %d \n", x);
		printf("Process ID of Shell is %d \n", getppid());
	}

	return 0;
}