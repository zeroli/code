#include <iostream>

class B {
public:
	virtual int f(int) {
		std::cout << "B::f(int) called \n";
	}
	void f(B*) {
		std::cout << "B:f(B*) called\n";
	}
};

class D: public B {
public:
	int f(int) {
		std::cout << "D:f(int) called\n";
	}
	int f() {
		std::cout << "D:f(B*) called\n";
	}
};

int main()
{
	D d;
	d.f(2);

	B b;
	d.B::f(&b);

	return 0;
}
