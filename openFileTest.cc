#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>

int main()
{
	int fd = open("a.txt", O_CREAT);
	if (fd<0) {
		printf("Error\n");
		return -1;
	}
	close(fd);
	printf("create file ok.\n");
	return 0;
}
