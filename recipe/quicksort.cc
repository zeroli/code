#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstdlib>

template <class T>
T median(const T& a, const T& b, const T& c)
{
	if (a < b) 
		if (b < c)
			return b;
		else if (a < c)
			return c;
		else
			return a;
	else if (b < c)
		return c;
	else if (a < c)
		return a;
	else
		return b;
}

template <class T>
T* partition(T* first, T* last, T pivot)
{
	while (1) {
		while(*first < pivot) ++first;
		--last;
		while (*last > pivot) --last;
		if (!(first < last)) return first;
		T tmp = *first;
		*first = *last;
		*last = tmp;
	//	swap(*first, *last);
		++first;
	}

}

template <class T>
void qs_loop(T* first, T* last)
{
	if (first+1 < last) {
	   T med = median(*first, *(first+(last-first)/2), *(last-1));
	   T* cut = partition(first, last, med);
	   qs_loop(first, cut);
	   qs_loop(cut, last);
	}
}

void quicksort(std::vector<int>& data)
{
	if (!data.empty()) {
		int* first = &data[0];
		int* last = &data[data.size()-1]+1;
		qs_loop(first, last);
	}
}

int main()
{
	std::cout << "Quick sort, input random number.\n";

	std::ostream_iterator<int> out(std::cout, " ");
	std::vector<int> data;
	for (int i = 0; i < 20; i++) 
		data.push_back(rand()%100);
	std::cout << "original random numbers:\n";
	std::copy(data.begin(), data.end(), out);
	std::cout << std::endl;

	quicksort(data);
	std::cout << "After sorted, numbers are: \n";	
	std::copy(data.begin(), data.end(), out);
	std::cout << std::endl;
	return 0;
}
	
