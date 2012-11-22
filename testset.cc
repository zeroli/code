#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::set<double> dataset;
	for (int i = 0; i < 10; i++)
		dataset.insert(i);
	
	std::copy(dataset.begin(), dataset.end(), std::ostream_iterator<double>(std::cout, ","));
	std::cout << "\n";

	std::cout << "insert 2.4, 5.6\n";
	double min = 2.4;
	double max = 5.6;
	std::set<double>::iterator itb = dataset.lower_bound(min),
								ite = dataset.lower_bound(max);
	dataset.erase(itb, ite);
	
	dataset.insert(min);
	dataset.insert(max);
	
	std::copy(dataset.begin(), dataset.end(), std::ostream_iterator<double>(std::cout, ","));
	std::cout << "\n";

	return 0;
}

