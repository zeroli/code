#include <iostream>

struct A {
	static const int i = 2;
	static const int j = 3;
	
	void print();
};


void A::print()
{
	int out = 0;
	int printout = out ? i : j;
	std::cout << printout << "\n";
}

int main()
{
	A a;
	a.print();
	return 0;
}

