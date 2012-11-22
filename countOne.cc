#include "stdio.h"
#include "math.h"
#include "stdlib.h"

/* this function has somethignworng */
unsigned long countOne(unsigned long N)
{
	unsigned long l = 0;
	unsigned long left = 0;
	int n = 0;
	int m = 0;
	while (pow(10, n) <= N) {		
		m = N%int(pow(10, n));
		if (m<10) 
			l += (m+1);
		n++;		
	}
	return l;
	unsigned int j = 0;
}

int main(int argc, char ** argv)
{
	if (argc<2) {
		fprintf(stderr, "usage: %s [N]\n", argv[0]);
		exit(0);
	}
	int N = atoi(argv[1]);
	printf("one counter = %u, for %u\n", countOne(N),N);
	return 0;
}

