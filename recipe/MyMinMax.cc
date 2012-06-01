#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

void printv(const std::vector<int>& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

void maxmin(const std::vector<int>& v, int& max, int& min)
{
	int size = v.size();
	int s = 1;
	if (size%2) {
		max = min = v[0];
	} else {
		max = (v[0]<v[1]?v[1]:v[0]);
		min = (v[0]<v[1]?v[0]:v[1]);
		s = 2;
	}
	for (int i = s; i < size-1; i+=2) {
		if (v[i] < v[i+1]) {
			if (v[i] < min) 
				min = v[i];
			if (v[i+1] > max)
				max = v[i+1];
		} else {
			if (v[i] > max)
				max = v[i];
			if (v[i+1] < min) 
				min = v[i+1];
		}
	}
}

int main()
{
	srand(time(0));
	std::vector<int> v;
	for (int i = 0; i < 20; i++) 
		v.push_back(int(rand()%100));
	printv(v);
	int max, min;
	maxmin(v, max, min);
	std::cout << "max=" << max << ",min="<<min<<std::endl;
	return 0;
}
