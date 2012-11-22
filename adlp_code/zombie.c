#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_pid;
	
	child_pid = fork();
	if (child_pid > 0) {
		sleep(150);
		printf("parent process exited: %d, %d\n", (int)getpid(), (int)getppid());
	} else {
		printf("parent process exited: %d\n", (int)getpid());
		exit(0);
	}
	return 0;
}
