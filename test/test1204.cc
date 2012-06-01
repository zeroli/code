#include <iostream>
#define DBL_MAX 1.7976931348623158e+308 

int main()
{
	std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
	std::cout << "sizeof(long double) = " << sizeof(long double) << std::endl;
	std::cout << DBL_MAX << std::endl;
	double min = -DBL_MAX-100;
	std::cout << "min = " << min << std::endl;
	if (min < -DBL_MAX) {
		std::cout << "< \n";
	}
	if ((long double)min + DBL_MAX < 1e-6L) {
		std::cout << "> value\n";
	}	
	std::cout << (long double)min + DBL_MAX << std::endl;
	if (min + DBL_MAX < 1e-6) {
		std::cout << "> value\n";
	}
	return 0;
}
