#include <iostream>
#include <cstdlib>

#define maxN2 40 
#define maxN  maxN2/2

int partition(int a[], int l, int r, int v)
{
	while (1) {
		while (a[l] < v) l++;
		while (a[r] > v) r--;
		if (l < r) {
			int tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
		} else
			return l;
		l++;
	}
}

void qsort(int a[], int l, int r)
{
	if (l < r) {
		int v = a[r];
		int m = partition(a, l, r, v);
		qsort(a, l, m-1);  //here , it must NOT "m"
		qsort(a, m, r);
	}
}

struct item {
	int key;
	int value;
};


item aux[maxN];

void merge(item a[], int l, int m, int r)
{
	int i, j, k;
	for (i=m+1; i > l; i--) aux[i-1] = a[i-1];
	for (j=m; j < r; j++) aux[r+m-j] = a[j+1];
	for (k = l; k <= r; k++)
		if (aux[j].key < aux[i].key)
			a[k] = aux[j--];
		else
			a[k] = aux[i++];
}

void mergesort(item a[], int l, int r)
{
	if (l < r) {
		int m = l+(r-l)/2;
		mergesort(a, l, m);
		mergesort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main()
{	
	srand(unsigned(time(0)));
	std::cout << "==============Quick Sort===============\n";
	std::cout << "original random data input: \n";
	int keys[maxN];// = {81,46,4,17,6,98,36,53,54,98,43};

	for (int i = 0; i < maxN; i++) {
		keys[i] = int(rand()%100);
		std::cout << keys[i] << " ";
	} 
	std::cout << "(" << maxN << ")" << std::endl;
	qsort(keys, 0, maxN-1);
	std::cout << "after qsort, the keys are :\n";
	for (int i = 0; i < maxN; i++)
		std::cout << keys[i] << " ";
	std::cout << "\n";
	std::cout << "===============Merge Sort==============\n";
	std::cout << "original random data input: \n";
	item a[maxN2];
	for (int i = 0; i < maxN2; i++) {
		a[i].key = int(rand()%100);
		a[i].value = i;
		std::cout << a[i].key << " ";
	}
	std::cout << "\n";
	mergesort(a, 0, maxN2-1);
	std::cout << "after merging sort, the sorted array:\n";
	for (int i = 0; i < maxN2; i++) {
		std::cout << a[i].key << " ";
	}
	std::cout << "\n";
	return 0;
}
	
