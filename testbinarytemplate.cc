#include <iostream>

template <int N>
class binary
{
public:
	static const int value =
		binary<N/10>::value * 2 
			+ N%10;
};		

template <>
class binary<0>
{
public:
	static const int value = 0;
};

int main()
{
	std::cout << binary<1010>::value << std::endl;
	return 0;
}
