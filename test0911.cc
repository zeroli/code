#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> va;
	for (int i = 0; i < 10; i++)
	{
		va.push_back(i);
	}

	for (std::vector<int>::iterator it = va.begin(); 
		it != va.end(); )
	{
		std::cout << *it << std::endl;
		if (*it == 2) {
			va.erase(it++);
//			std::cout << *it << std::endl;
			continue;
		}
		++it;
	}
	std::copy(va.begin(), va.end(), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}

