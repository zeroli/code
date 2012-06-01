#include <stdio.h>
#include <fcntl.h>

#ifndef BUFSIZ
#define BUFSIZ 1024
#endif 

int main()
{
	char buf[BUFSIZ];
	int n;
	
	while ((n=read(0, buf, BUFSIZ)) > 0)
		write(1, buf, n);
	return 0;
}	
