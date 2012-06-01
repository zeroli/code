#include <iostream>
#include <algorithm>
#include <cmath>

const char* convertToString(char buf[], int val)
{
	static char digits[19] = 
		{ '9', '8', '7', '6', '5', '4', '3', '2', '1',
		  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	static const char* zero = digits + 9;
	int i = val;
	char* p = buf;
	do {
		// lsd - least significant digit
		int lsd = i % 10;
		i /= 10;
		*p++ = zero[lsd];
		std::cout << "result=" << i << ", remainder=" << lsd << "\n";
	} while (i != 0);

	if (val < 0) {
		*p++ = '-';
	}
	*p = '\0';
	std::reverse(buf, p);
	return p;
}

int main()
{
	char buf[100];
	int val = 300120;
	std::cout << "number : " << val << " converted to string: "; 
	convertToString(buf, val);
	std::cout << buf << std::endl;
	val = -300120;
	std::cout << "number : " << val << " converted to string: ";
	convertToString(buf, val);
	std::cout << buf << std::endl;


	float f = +10.2;
	std::cout << "f=" << f << ", floor(f/2)= " << std::floor(f/2) << ", ceil(f/2)=" << std::ceil(f/2) << std::endl;
	f = -10.2;
	std::cout << "f=" << f << ", floor(f/2)= " << std::floor(f/2) << ", ceil(f/2)=" << std::ceil(f/2) << std::endl;
	return 0;
}
