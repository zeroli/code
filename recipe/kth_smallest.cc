#include "cpp_header.h"

int partition(std::vector<int>& a, int l, int r)
{
	int i = l, j = l;
	int p = a[r];
	while (j<r) {
		if (a[j] < p) {
			std::swap(a[i], a[j]);
			i++; 
		}
		j++;
	}
	std::swap(a[r], a[i]);
	return i;
}

void select_kth_smallest(std::vector<int>& a, int l, int r, int k)
{
	while (1) {
		int cut = partition(a, l, r);
#if 0
		std::copy(a.begin()+l, a.begin()+cut, std::ostream_iterator<int>(std::cout, " "));
		std::cout << " <=" << a[cut] << "=> ";
		std::copy(a.begin()+cut+1, a.begin()+r+1, std::ostream_iterator<int>(std::cout, " "));
		std::cout << "cut("<<cut<<"),k("<<k<<"),l("<<l<<"),r("<<r<<")\n";
#endif
		if (cut-l+1==k) 
			break;
		else if (k < cut-l+1) 
			r = cut-1;
		else {
			k = k-cut-1+l;
			l = cut+1;
		}
	}
}

void select_kth_smallest2(std::vector<int>& a, int l, int r, int k)
{
	while (1) {
		int cut = partition(a, l, r);
		if (cut+1==k)
			break;
		else if(k < cut+1)
			r = cut-1;
		else
			l = cut+1;
	}
}

void qsort(std::vector<int>& a, int l, int r)
{
	if (l < r) {
		int cut = partition(a, l, r);
		qsort(a, l, cut-1);
		qsort(a, cut+1, r);
	}
}

int main()
{
	std::vector<int> a;
	srand(time(0));
	std::cout << "Please input the # of numbers for random:\n";
	int N;
	std::cin >> N;
	assert(N>0);
	for (int i = 0; i < N; i++)
		a.push_back(int(rand())%100);

	std::copy(a.begin(), a.end(),std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	std::vector<int> aa(a);
	std::cout << "Please input the k for kth smallest elements(starting from 1):\n";
	int k ;
	for (int i = 1; i <=N; i++) {
		std::cout << "select " << i << "th smallest elements:\n";
		std::vector<int> ab(aa);
		select_kth_smallest(ab, 0, ab.size()-1, i);
		std::copy(ab.begin(), ab.begin()+i, std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n";
	}
	std::cout << "=======================\n";
    for (int i = 1; i <=N; i++) {
        std::cout << "select " << i << "th smallest elements:\n";
        std::vector<int> ab(aa);
        select_kth_smallest2(ab, 0, ab.size()-1, i);
        std::copy(ab.begin(), ab.begin()+i, std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
    }

	qsort(aa, 0, aa.size()-1);
	std::cout << "qsort result for all data:\n";
	std::copy(aa.begin(), aa.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	return 0;
}
