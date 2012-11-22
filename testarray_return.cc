#include <iostream>
#include <boost/array.hpp>

template <int N>
int (*return_arrayP())[N]
{
	static int array[] = {2, 3, 4};
	return &array;
}

template <int N>
int (&return_arrayR())[N]
{
	static int array[] = {2, 3, 4};
	return array;
}

int main()
{
	static const int N = 3;
	// test return pointer to array
	std::cout << "test return pointer to array\n";
	int (*arrayP)[N] = return_arrayP<N>();
	for (int i = 0; i < N; i++) {
		std::cout << (*arrayP)[i] << ", ";
	}
	std::cout << "\n";

	// test return reference to array
	std::cout << "test return reference to array\n";
	int (&arrayR)[N] = return_arrayR<N>();
	for (int i = 0; i < N; i++) {
		std::cout << arrayR[i] << ", ";
	}
	std::cout << "\n"; 
	
	// boost::array return reference to array
	// to downcast to T*
	std::cout << "use boost::array to return reference to array, and then downcast to T*\n";
	int* arrayb = NULL;
	boost::array<int, N> oneArray = {1, 2, 3};
	arrayb = boost::get_c_array(oneArray);
	for (int i = 0; i < N; i++) {
		std::cout << arrayb[i] << ", ";
	}
	std::cout << "\n";
	return 0;
}
