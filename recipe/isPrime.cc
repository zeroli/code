#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

bool isPrime(int a)
{
	for (int i = 2; i*i < a+1; i++) 
		if (!(a%i))
			return false;
	return true;
}

void getPrimes(std::vector<int>& a)
{
	std::vector<int>::iterator it = a.begin();
	int amax = a.back();
	for (; it!=a.end(); ++it) {
		int v = *it;
		if (v*v > amax)
			break;
		for (std::vector<int>::iterator itt = it+1; 
				itt!=a.end(); ) {
			if (!(*itt % v))
				itt=a.erase(itt);
			else
				++itt;			
		}
	}
}

int main()
{
	std::vector<int> vPrimes;
	for (int i = 2; i < 100; i++) 
		if (isPrime(i)) 
			vPrimes.push_back(i);
	std::copy(vPrimes.begin(), vPrimes.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	vPrimes.clear();
	for (int i = 2; i < 100; i++)
		vPrimes.push_back(i);
	getPrimes(vPrimes);
	std::copy(vPrimes.begin(), vPrimes.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	return 0;
}
