#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char*argv[]) {
	struct stat file;
	int n;

	if (argc != 2) {
		printf("Number of Arguements provided != 2 \n");
		printf("Arguements Required: \n");
		printf("Filename \n");
		exit(-1);
	}

	if ((n = stat(argv[1], &file)) == -1) {
		perror(argv[1]);
		exit(-1);
	}

	printf("User ID : %d \n", file.st_uid);
	printf("Group ID : %d \n", file.st_gid);
	printf("Block Size : %d\n", file.st_blksize);
	printf("Blocks Allocated : %d\n", file.st_blocks);
	printf("i-Node Number : %d \n", file.st_ino);
	printf("\n");

	printf("Last Accessed : %s", ctime(&(file.st_atime)));
	printf("Last Modified : %s", ctime(&(file.st_mtime)));
	printf("\n");

	printf("File Size : %d Bytes \n", file.st_size);
	printf("Number Of Links : %d \n", file.st_nlink);

	printf("Directory : ");
	printf((S_ISDIR(file.st_mode)) ? "d " : "- ");
	printf("\n");

	printf("Permissions : \n");

	printf("User : ");
	printf((file.st_mode & S_IRUSR) ? "r " : "- ");
	printf((file.st_mode & S_IWUSR) ? "w " : "- ");
	printf((file.st_mode & S_IXUSR) ? "x " : "- ");
	printf("\n");

	printf("Group : ");
	printf((file.st_mode & S_IRGRP) ? "r " : "- ");
	printf((file.st_mode & S_IWGRP) ? "w " : "- ");
	printf((file.st_mode & S_IXGRP) ? "x " : "- ");
	printf("\n");

	printf("Other : ");
	printf((file.st_mode & S_IROTH) ? "r " : "- ");
	printf((file.st_mode & S_IWOTH) ? "w " : "- ");
	printf((file.st_mode & S_IXOTH) ? "x " : "- ");
	printf("\n");

	if (file.st_mode & S_IFREG) {
		printf("Type : Regular \n");
	}

	if (file.st_mode & S_IFDIR) {
		printf("Type : Directory \n");
	}

	return 0;
}