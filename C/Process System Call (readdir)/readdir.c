#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct dirent *dptr;
	DIR *dname;

	if (argc != 2) {
		printf("Insufficient Arguments \n");
		printf("Other Arguments Required : \n");
		printf("Directory Name \n");
		exit(-1);
	}

	if ((dname = opendir(argv[1])) == NULL) {
		perror(argv[1]);
		exit(-1);
	}

	while (dptr = readdir(dname)) {
		printf("%s \n", dptr->d_name);
	}

	closedir(dname);

	printf("\n");

	return 0;

}