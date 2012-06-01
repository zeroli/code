#include <iostream>

// recursion method
unsigned int factorial(unsigned int n)
{
	if (n==0)
		return 1;
	return n*factorial(n-1);
}

/** 
 * meta programming
 */
template <int N>
struct Factorial
{
	enum { value = N*Factorial<N-1>::value };
};

// ending condition
template <>
struct Factorial<0>
{
	enum { value = 1 };
};

void foo()
{
	int x = Factorial<4>::value;
	int y = Factorial<0>::value;
}

int main()
{
	std::cout << "recursion method for factorial(4): "
			<< factorial(4) << "\n";
	std::cout << "meta-programming method for factorial(4): "
			<< Factorial<4>::value << "\n";
	return 0;
}


