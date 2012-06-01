#include "stdio.h"
#include "string.h"

#define N 11

int bisearch(char** arr, int b, int e, char* v)
{
	int minIdx = b, maxIdx = e, midIdx;
	while (minIdx < maxIdx-1) {
		midIdx = minIdx+(maxIdx-minIdx)/2;
		if (strcmp(arr[midIdx], v)<=0)
			minIdx = midIdx;
		else
			maxIdx = midIdx;
	}
	if (!strcmp(arr[maxIdx], v))
		return maxIdx;
	else if (!strcmp(arr[minIdx], v))
		return minIdx;
	else
		-1;
}

int bisearch2(int arr[N], int b, int e, int v)
{
	int min = b, max = e, mid;
	while (min < max-1) {
		mid = min+(max-min)/2;
		printf("min=%d, mid=%d, max=%d\n", min, mid,max);
		if (arr[mid] <= v) 
			min = mid;
		else
			max = mid-1;
	}
	if (v==arr[max])
		return max;
	else if (v==arr[min])
		return min;
	else 
		return -1;
}

int main()
{
	int arr[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("index = %d for value = %d\n", bisearch2(arr, 4, 4, 4), 4);
	return 0;
}
