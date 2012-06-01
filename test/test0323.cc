#include <iostream>

class A {
public:
	A() {}
	
	virtual A* func1(int a) {
		std::cout << "A* A:func1(int)\n";
	}
	void func2() {
		std::cout << "A::func2()\n";
	}
};

class B : public A{
public:
	B() {};
	
	B* func1(int b) {
		std::cout << "B* B:func1(int)\n";
	}
	double func1(double b) {
		std::cout << "double B:func1(double)\n";
	}
	void func2() {
		std::cout << "B:func2()\n";
	}
};

int main()
{
	char c = -1;
	printf("%X\n", c);
	A* a = new B;
	a->func1(1);

	B b;
	b.func1(3.);	
	a->func2();
	delete a;
	return 0;
}
	
