#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <vector>

void print(const std::vector<int>& s)
{
	static int n = 1;
	printf("%d:", n++);
	printf("[");
	for (int i = 0; i < s.size(); i++)
		printf(" %d ", s[i]);
	printf("]\n");
}

void permutation(std::vector<int>& v, int beg, int end)
{
	if (beg > end) {
		print(v);
		return;
	}
	for (int i = beg; i <= end; i++) {
		std::swap(v[i], v[beg]);
		permutation(v, beg+1, end); // pleate note, here always beg+1, not i+1
		std::swap(v[i], v[beg]);
	}		
}

void pm(std::vector<int>& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	printf("\nfull permulation are:\n");
	permutation(v, 0, v.size()-1);
}

void print(const std::vector<int>& v, int beg, int end)
{
	static int n = 1;
	printf("%d:", n++);
	printf("[");
	std::copy(v.begin()+beg, v.begin()+end+1, std::ostream_iterator<int>(std::cout, " "));
	printf("]\n");
}

void fullset(std::vector<int>& v)
{
	printf("full set are:\n");
	for (unsigned int i = 0; i < v.size(); i++) {
		print(v, i, i);
		for (unsigned int j = i+1; j < v.size(); j++) {
			for (int k = 0; k < v.size()-j; k++) {
				std::swap(v[j+k], v[j]);
				print(v, i, j);
				std::swap(v[j+k], v[j]);
			}
		}
	}
}

int main()
{
	// srand(time(0));
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
//	v.push_back(6);
	pm(v);
	fullset(v);
	return 0;
}
