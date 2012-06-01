#include <iostream>

class A {
public:
	~A() { std::cout << "A "; }
};

class B : public A {
public :
	~B() { std::cout << "B "; }
};

int main()
{
	A* a = new B();
	B* b = new B();
	
	delete a;
	delete b;
	return 0;
}
