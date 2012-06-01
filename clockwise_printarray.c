#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 7
#define N 6 

void clockwise_print(int a[][N], int l, int r, int t, int b)
{
	int i, j;
	j = l;
	while (j < r) 
		printf("%d ", a[t][j++]);
	
	i = t;
	while (i < b) 
		printf("%d ", a[i++][r]);
	 
	j = r;
	while (j > l)
		printf("%d ", a[b][j--]);
	
	i = b;
	while (i > t) 
		printf("%d ", a[i--][l]);
	
	if (l==r && t==b)
		printf("%d ", a[t][l]);
	if (l<=r || t<=b)
		clockwise_print(a, l+1, r-1, t+1, b-1);		
}

int main()
{
	int a[M][N];
	int i, j;
	srand(time(0));
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = (int)rand()%100;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("clockwise print the array into one sequence:\n");
	clockwise_print(a, 0, N-1, 0, M-1);
	printf("\n");
	return 0;
}

	
	
	
	
