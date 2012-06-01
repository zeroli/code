#include <iostream>
#include <cmath>

int parent(int i)
{
	return (int)floor(i/2);
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

void maxHeapify(int A[], int i, int heapsize)
{
	int temp;
	int l = left(i);
	int r = right(i);
	int largest;
	if (l < heapsize && A[l] > A[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if (r < heapsize && A[r] > A[largest]) {
		largest = r;
	}
	if (largest!=i) {
		temp = A[i];	
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, largest, heapsize);
	}
}

void buildMaxHeap(int A[], int heapsize)
{
	for (int i = heapsize-1; i >= 0; i--)
		maxHeapify(A, i, heapsize);
}

void print(int A[], int heapsize)
{
	for (int i = 0; i < heapsize; i++) 
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

void heapSort(int A[], int heapsize)
{
	int temp;
	int HEAPSZ = heapsize;
	buildMaxHeap(A, heapsize);
	print(A, HEAPSZ);
	for (int i = heapsize-1; i > 0; i--) {
		/* Each time, place max value back of array */
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapsize = heapsize-1;
		maxHeapify(A, 0, heapsize);  /* bubble max value at 0 */
	}
	print(A, HEAPSZ);
}
	
int main()
{
	int A[10] = { 3, 2, 6, 9, 4, 5, 1, 7, 8, 10};
	print(A, 10);
	heapSort(A, 10);
	return 0;
}


