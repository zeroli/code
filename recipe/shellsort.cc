#include <iostream>

/*
 * ShellSort - one advanced version of insertion sort
 */
void shellSort(int A[], int size)
{
	int gap = 0;
	while (3*gap+1<=size) {
		gap = 3*gap+1;
	}
	while (gap > 0) {
		for (int i = gap ; i < size; i++) {
			int j = i-gap;
			int temp = A[i];
			while (j >= 0 && A[j] > temp) {
				A[j+gap] = A[j];
				j -= gap;
			}
			A[j+gap] = temp;
		}
		gap = (gap-1)/3;
	}
}

void print(int A[], int size)
{
	for (int i = 0;i < size; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";
}

int main()
{
	int A[10] = { 3, 4, 1, 9, 10, 5, 2, 8, 7, 6 };
	print(A, 10);
	shellSort(A, 10);
	print(A, 10);
	return 0;
}	
