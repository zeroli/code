#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

const int HEAP_SIZE = 13;

void printv(const std::vector<int>& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

int parent(int);
int left(int);
int right(int);
void Max_Heapify(std::vector<int>&, int , int);
void Build_Max_Heap(std::vector<int>&);
void HeapSort(std::vector<int>&);

// below i is starting from 0
int parent(int i)
{
	return (int)floor((i+1)/2-1);
}

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*(i+1);
}

void Max_Heapify(std::vector<int>& v, int i, int upbound)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if (l < upbound && v[l] > v[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if (r < upbound && v[r] > v[largest]) {
		largest = r;
	}
	if (largest != i) {
		std::swap(v[i], v[largest]);
		Max_Heapify(v, largest, upbound);
	}
}

void Build_Max_Heap(std::vector<int>& v)
{
	int size = v.size();
	for (int i = parent(size-1); i >= 0; i--) {
		Max_Heapify(v, i, size);
	}
}

void HeapSort(std::vector<int>& v)
{
	Build_Max_Heap(v);
	int heap_size = v.size();
	for (int i = heap_size-1; i >= 1; i--) {
		std::swap(v[0], v[i]);
		Max_Heapify(v, 0, i);
	//	printf("i=%d: ", i);
	//	printv(v);
	}
}

int main(void)
{
	srand(time(0));
	std::vector<int> v;
	for (int i = 0; i < HEAP_SIZE; i++) 
		v.push_back(int(rand()%HEAP_SIZE));
    printf("Original data sequence is:\n");
	printv(v);

	HeapSort(v);
	printf("After heap sorting, the data sequence is:\n");
	printv(v);
	return 0;
}
