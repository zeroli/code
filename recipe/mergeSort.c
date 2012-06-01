#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int a[], int aux[], int l, int m, int r)
{
	int ibeg = l, iend = m;
	int jbeg = m, jend = r+1;
	int i = l;
	while (ibeg < iend && jbeg < jend) 
		if (a[ibeg] < a[jbeg]) {
			aux[i++] = a[ibeg];
			ibeg++;
		} else {
			aux[i++] = a[jbeg];
			jbeg++;
		}
	while (ibeg < iend) 
		aux[i++] = a[ibeg++];
	while (jbeg < jend)
		aux[i++] = a[jbeg++];
	i = l;
	while (i <= r) {
		a[i] = aux[i];		
		i++;
	}
}

void mergesort(int a[], int aux[], int l, int r)
{
	if (l < r) {
		int m = l+(r-l)/2;
		mergesort(a, aux, l, m);
		mergesort(a, aux, m+1, r);
		merge(a, aux, l, m+1, r);
	}
}

int main()
{
	int a[20];
	int aux[20];
	int i = 0;
	
	srand(time(0));
	for (i = 0;i < 20; i++) {
		a[i] = (int)rand()%100;	
		aux[i] = 0;
		printf("%d ", a[i]);
	}
	printf("\n");
	
   	mergesort(a, aux, 0, 19);
	for (i = 0; i < 20; i++) 
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
