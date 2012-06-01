#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	char w[16] = {0};
	printf("weight=%s\n", w);

	std::vector<int> a(20, 0);
	for (int i = 0; i < 20; i++) {
		a[i] = i+1;
	}
	std::vector<int>::iterator it = a.begin();
	for (; it!=a.end(); ) {
		if (*it == 10) {
			it = a.erase(it);
			continue;
		}
		++it;
	}
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, ","));
	std::cout << "\n";
	return 0;
}


