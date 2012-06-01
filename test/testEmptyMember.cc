#include <iostream>

class Base {
public:
	void func() { std::cout << "Base::func()" << std::endl; }
};

class A {
public:
	int a;
	Base b;
	char be;
};

int main()
{
	A aa;
	std::cout << sizeof(aa) << std::endl;
	std::cout << sizeof(aa.b) << std::endl;
	return 0;
}
