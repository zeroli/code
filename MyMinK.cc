#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

void printv(const std::vector<int>& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

void printv(const std::vector<int>& v, int l, int r)
{
	std::copy(v.begin()+l, v.begin()+r+1, std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

void exchange(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(std::vector<int>& v, int l, int r)
{
	int m = int(rand()%(r-l+1)+l);
	exchange(v[m], v[r]);
	int i = l-1;
	for (int j = l; j <= r-1; j++) {
		if (v[j] <= v[r]) {
			i++;
			exchange(v[i], v[j]);
		}
	}
	exchange(v[i+1], v[r]);
	return i+1;
}

int minK(std::vector<int>& v, int l, int r, int k)
{
	int key = -1;
	int m = partition(v, l, r);
//	printf("m=%d: ", m);
//	printv(v, l, r);
	if (m == k) key = v[m];
	else if (k < m) 
		key = minK(v, l, m-1, k);
	else 
		key = minK(v, m+1, r, k);
	return key;
}

int minK_iter(std::vector<int>& v, int l, int r, int k)
{
	while (l <= r) {
		int m = partition(v, l, r);
		printf("v[%d]=%d: ", m, v[m]);
		printv(v);
		if (m == k)  return v[k];
		else if (k < m) 
			r = m-1;
		else
			l = m+1;
	}
}

int MyMinK(std::vector<int>& v, int k)
{
	assert(k<v.size());
	int key = minK_iter(v, 0, v.size()-1, k);
	return key;
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: $program N K\n");
		exit(1);
	}
	int N = atoi(argv[1]);
	int k = atoi(argv[2]);
	srand(time(0));
	std::vector<int> v;
	for (int i = 0; i < N; i++)
		v.push_back(int(rand()%100));
	printv(v);
	std::vector<int> vtmp(v);
	int kth = MyMinK(v, k);
	std::sort(vtmp.begin(), vtmp.end());
	std::cout << "The sorted data sequence is:\n";
	printv(vtmp);
	printf("The %dth min value: %d\n", k, kth);
	
	return 0;
}

