#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	srand(time(0));

	int N = 20;	// # of number
	int M = 1000;	// number range
	std::vector<int> a(N);
	for (int i = 0; i < N; i++)
		a[i] = (int)rand()%M;
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";	
 
	unsigned int nbytes = M%8 ? (M/8+1) : (M/8);
	std::cout << "nbytes = " << nbytes << "\n";

	char* p = new char [nbytes];
	memset(p, 0, sizeof(char)*nbytes);

	for (int i = 0; i < N; i++) {
		unsigned int index = a[i]/8;
		unsigned int bitpos = a[i]%8;
		char* tmp = p+index;
		*tmp |= 1 << bitpos;
		//std::cout << "bit pos set to 1 : " << 8*index+bitpos << "\n";
	}
	for (int i = nbytes-1; i >= 0; i--) {
		printf("%02X ", (char)*(p+i)&0xFF);
	}	
	std::cout << "\n";
	delete [] p;
	return 0;
}
