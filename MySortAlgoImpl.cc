#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>
#include <cmath>

int NUM = 0;

void printv(const std::vector<int>& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void printv(const std::vector<int>& v, int l, int h)
{
	std::copy(v.begin()+l, v.begin()+h+1, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int exchange(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

typedef void (*SortAlgoFunc)(std::vector<int>& v);

void MyQuickSort(std::vector<int>& v);
void MyHeapSort(std::vector<int>& v);
void MyInsertSort(std::vector<int>& v);
void MyMergeSort(std::vector<int>& v);
void MySelectSort(std::vector<int>& v);
void MyCountSort(std::vector<int>& v);

int main(int argc, char** argv)
{
	if (argc < 5) {
		fprintf(stderr, "Usage: $program -n $NUM -algo $algoname\n \
$NUM: number of random data\n \
$algoname: quicksort | heapsort | insertsort | mergesort | selectsort | countsort\n");
		exit(1);
	}
	char* algoname = 0;
	for (int i = 1; i < argc; i+=2) {
		if (!strcmp(argv[i], "-n")) 
			NUM = atoi(argv[i+1]);
		else if (!strcmp(argv[i], "-algo")) 
			algoname = argv[i+1];
	}		
	SortAlgoFunc sortFunc = 0;
	if (!strcmp(algoname, "quicksort")) {
		sortFunc = MyQuickSort;
	} else if (!strcmp(algoname, "heapsort")) {
		sortFunc = MyHeapSort;
	} else if (!strcmp(algoname, "insertsort")) {
		sortFunc = MyInsertSort;
	} else if (!strcmp(algoname, "mergesort")) {
		sortFunc = MyMergeSort;
	} else if (!strcmp(algoname, "selectsort")) {
//		sortFunc = MySelectSort;
	} else if (!strcmp(algoname, "countsort")) {
		sortFunc = MyCountSort;
	} else {
		fprintf(stderr, "Unknown sort algo name!\n");
		exit(1);
	}

	srand(time(0));
	std::vector<int> v, vtmp;
	for (int i = 0; i < NUM; i++) 
		v.push_back(int(rand()%NUM));
	std::cout << "Original data sequence is:\n";
	printv(v);
	sortFunc(v);
	printf("After \"%s\", the data sequence is:\n", algoname);
	printv(v);
	return 0;
}

/* quicksort */	
int partition1(std::vector<int>& v, int l, int h)
{
	int i = l-1;
	int pivot = v[h];
	int j = l;
	while (j < h) {
		if (v[j] < pivot) {
			i++;
			exchange(v[i], v[j]);
		}
		j++;
	}
	exchange(v[i+1], v[h]);
	return i+1;
}

int partition2(std::vector<int>& v, int l, int h)
{
	int m = l+(h-l)/2;
	int i = l;
	int j = h;
	int pivot = v[m];
	while (1) {
		while (v[i] < pivot) i++;
		while (v[j] > pivot) j--;
		if (!(i<j)) {
	//		printv(v, l, h);
	//		printf("m=%d,i=%d,j=%d(l=%d,h=%d)\n", m,i, j, l, h);
			return j;
		}
		exchange(v[i], v[j]);
		i++;j--;
	}
}

void myQuickSort1(std::vector<int>& v, int l, int h)
{
/*
  Please note, returned m is the loc of pivot, 
  in below myQuickSort1, can remove m, since left of m, all <= pivot
  right of m, all >= pivot
 */
	if (l < h) {
		int m = partition1(v, l, h);
		myQuickSort1(v, l, m-1);
		myQuickSort1(v, m+1, h);
	}
}

void myQuickSort2(std::vector<int>& v, int l, int h)
{
/*
 if partition2 return i, please call below
  myQuickSort2(v, l, m-1);
  myQuickSort2(v, m, h);
 else if it return j, please call below
  myQuickSort2(v, l, m);
  myQuickSort2(v, m+1, h);
*/
	if (l < h) {
		int m = partition2(v, l, h);
		myQuickSort2(v, l, m);
		myQuickSort2(v, m+1, h);
	}
}

void MyQuickSort(std::vector<int>& v)
{
	myQuickSort2(v, 0, v.size()-1);
}

/* heapsort */
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

void MyHeapSort(std::vector<int>& v)
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

/* insertsort */
void MyInsertSort(std::vector<int>& v)
{
	int i;
	for (int j = 1; j < v.size(); j++) {
		int va = v[j];
		i = j-1;
		while (i > -1&& v[i] > va) {
			v[i+1] = v[i];
			i--;
		}
		v[i+1] = va;
	}
}

/* mergesort */
void merge(std::vector<int>& v, std::vector<int>& vtmp, int l, int m, int r)
{
	int ibeg = l, iend = m;
	int jbeg = m+1, jend = r;
	int j = l;
	while (ibeg <= iend && jbeg <= jend) {
		if (v[ibeg] < v[jbeg]) {
			vtmp[j++] = v[ibeg];
			ibeg++;
		}
		else { //if (v[ibeg] > v[jbeg]) {
			vtmp[j++] = v[jbeg];
			jbeg++;
		}
	}
	while (ibeg <= iend) {
		vtmp[j++] = v[ibeg];
		ibeg++;
	}
	while (jbeg <= jend) {
		vtmp[j++] = v[jbeg];
		jbeg++;
	}
	// copy back
	for (int i = l; i <= r; i++) 
		v[i] = vtmp[i];		
}

void MergeSort(std::vector<int>& v, std::vector<int>& vtmp, int l, int r)
{
	if (l < r) {
		int m = l+(r-l)/2;
		MergeSort(v, vtmp, l, m);
		MergeSort(v, vtmp, m+1, r);
		merge(v, vtmp, l, m, r);
	}
}

void MyMergeSort(std::vector<int>& v)
{
	std::vector<int> vtmp(v);
	MergeSort(v, vtmp, 0, v.size()-1);	
}

/* selectsort */

/* countsort */
void MyCountSort(std::vector<int>& v)
{
	std::vector<int> C(NUM, 0);
	std::vector<int> B(v.size());
	for (unsigned int i = 0; i < v.size(); i++) 
		C[v[i]] = C[v[i]] + 1;
	for (unsigned int i = 1; i < NUM; i++)
		C[i] = C[i]+C[i-1];
	for (int i = int(v.size())-1; i >= 0; i--) {
		B[C[v[i]]-1] = v[i];
		C[v[i]] -= 1;
	}
	std::swap(v, B);
}
