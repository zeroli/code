#include <iostream>
#include <cstdlib>
#include <ctime>

void insertionSort(int arr[], int l, int r)
{
	int i = l; 
	int j = 0;
	while (i < r) {
		j = i+1;
		int e = arr[j];
		while (j > l && arr[j-1] > e) {
			arr[j] = arr[j-1];	
			j--;
		}
		arr[j] = e;
		i++;
	}
}

int main()
{
	srand((unsigned)time(0));
	int arr[10];
	std::cout << "original unsorted array: \n";
	for (int i = 0; i < 10; i++) {
		int tmp = (int)(rand()%100);
		arr[i] = tmp;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	insertionSort(arr, 0, 9);
	std::cout << "sorted array after insertion sort:\n";
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	return 0;	
}
