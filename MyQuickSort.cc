#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

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

int main()
{
	const int N = 100;
	srand(time(0));
	std::vector<int> v, vtmp;
	for (int i = 0; i < N; i++) 
		v.push_back(int(rand()%N));
	vtmp.insert(vtmp.end(), v.begin(), v.end());
	std::cout << "Original data sequence is:\n";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	myQuickSort1(v, 0, N-1);
	std::cout << "After quicksort(1), the data sequence is:\n";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	myQuickSort2(vtmp, 0, N-1);
	std::cout << "After quicksort(2), the data sequence is:\n";
	std::copy(vtmp.begin(), vtmp.end(), std::ostream_iterator<int>(std::cout, " "));
   	std::cout << std::endl;

	assert(v==vtmp);
	return 0;
}
