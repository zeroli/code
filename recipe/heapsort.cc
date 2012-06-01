#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>

// build one maximum heap 
template <typename T>
void heapsort(std::vector<T>& a)
{
	int sz = (int)a.size();
	for (int i = sz/2; i >= 0; i--)
		percDown(a, i, sz);
	std::cout << "build heap is done.\n";	
	for (int j = sz-1; j > 0; j--) {
		std::swap(a[0], a[j]);
		percDown(a, 0, j);
	}
}

inline int leftChild(int i)
{
	return 2*i+1;
}

template <typename T>
void percDown(std::vector<T>& a, int i, int n)
{
	int child;
	T tmp;
	for (tmp = a[i]; leftChild(i) < n; i = child) {
		child = leftChild(i);
		if (child != n-1 && a[child] < a[child+1])
			child++;
		if (tmp < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = tmp;
}

int main()
{
	srand(time(0));
	
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(int(rand()%30));

	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	std::cout << "call heapsort function, and then result is :\n";
	heapsort(a);
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	return 0;
}	
