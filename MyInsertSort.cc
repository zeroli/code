#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <vector>

void printv(const std::vector<int>& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void myInsertSort(std::vector<int>& v)
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

int main()
{
	srand(time(0));
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(int(rand()%10));
	std::cout << "original data sequence is:\n";
	printv(v);
	myInsertSort(v);
	std::cout << "after insertion sort, the data sequence is:\n";
	printv(v);
	return 0;
}
