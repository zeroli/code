#include <iostream>
#include <vector>
#include <memory>

class A {
public:
	A(int i) {
		if (i!=1) {
			std::vector<int> a;
			a.at(0) = 1;
		} else
			std::cout << "ctor ok." << std::endl;
	}
	~A() {
		std::cout << "A:dtor." << std::endl;
	}
};

void f()
{
	try {
		A a(1);
		a.~A();
		new (&a) A(2);	/* here, throw one exception, but still destroy a again  */
	} catch(...) {
		std::cout << "catch exception." << std::endl;
	}
}

int main()
{
	f();		
	return 0;
}

