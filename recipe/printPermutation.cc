#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cassert>

int n=0;

void swap(int* a, int* b)
{
	int m = *a;
	*a = *b;
	*b = m;
}

void perm(int list[], int k, int m)
{
	int i;
	if (k==m) {
		for (i = 0; i <= m; i++)
			printf("%d ", list[i]);
		printf("\n");
		n++;
	} else {
		for (i = k; i <= m; i++) {
			swap(&list[k], &list[i]);
			perm(list, k+1, m);
			swap(&list[k], &list[i]);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc!=2) {
		fprintf(stderr, "Usage: %s [n]\n", argv[0]);
		exit(-1);
	}
	int m = atoi(argv[1]);
	assert(m);
	int* list = new int [m];	
	for (int i = 0;i < m; i++) 
		list[i] = i;
	perm(list, 0, m-1);
	printf("total : %d\n", n);
	delete [] list;
	return 0;
}
