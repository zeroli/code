#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <vector>

int partition2(std::vector<int>& a, int l, int r)
{
	int i = l;
	int j = l;
	while (j < r) {
		if (a[j] < a[r]) {			
			std::swap(a[i], a[j]);
			i++;
		}
		j++;
	}
	std::swap(a[i], a[r]);
	return i;

}

int partition1(std::vector<int>& a, int l, int r)
{
	int i=l, j=r-1;
	while (1) {
		while (a[i] < a[r]) i++;
		while (a[j] > a[r]) j--;
		if (!(i<j)) break;
		std::swap(a[i], a[j]);			
	}
	std::swap(a[i], a[r]);
	return i;
}

void qsort2(std::vector<int>& a, int l, int r)
{	
	if (l < r) {
		int m = partition2(a, l, r);
    	std::cout << "L(";
        std::copy(a.begin()+l, a.begin()+m, std::ostream_iterator<int>(std::cout, " "));
        std::cout << ") <="<<*(a.begin()+m)<<"=> R(";
        std::copy(a.begin()+m+1, a.begin()+r+1, std::ostream_iterator<int>(std::cout, " "));
        std::cout << ")\n";

		qsort2(a, l, m-1);
		qsort2(a, m+1, r);
	}
}

void qsort1(std::vector<int>& a, int l, int r)
{
	if (l < r) {
		int m = partition1(a, l, r);
		std::cout << "L(";
		std::copy(a.begin()+l, a.begin()+m, std::ostream_iterator<int>(std::cout, " "));
		std::cout << ") <="<<*(a.begin()+m)<<"=> R(";
		std::copy(a.begin()+m+1, a.begin()+r+1, std::ostream_iterator<int>(std::cout, " "));
		std::cout << ")\n";

		qsort1(a, l, m-1);
		qsort1(a, m+1, r);
	}
}

int main()
{
	srand(time(0));
	std::vector<int> a;
	std::cout << "Please enter the number of random values:\n";
	int N = 20;
	std::cin >> N; 
	for (int i = 0; i < N; i++) 
		a.push_back(int(rand()%100));
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	std::vector<int> a1(a);
	std::cout << "qsort -v1:\n";
	qsort1(a1, 0, a1.size()-1);	
	std::cout << "====>";
	std::copy(a1.begin(), a1.end(), std::ostream_iterator<int>(std::cout, " "));	
	std::cout << "\n";

	std::cout << "qsort -v2:\n";
	qsort2(a, 0, a.size()-1);
	std::cout << "====>";
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));	
	std::cout << "\n";

	assert(a==a1);
	if (a==a1) 
		std::cout << "2 versions got same result!\n";
	return 0;
}

