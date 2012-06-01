#include <iostream>

class A {
public:
	void calc() const {
		i = 1;
	}
	void print() const {
		std::cout << "A" << std::endl;
	}
private:
    mutable	int i;
};

void f(const A& pa)  // can not compile
{
	pa.print();
}

int main()
{
	A a;
	a.calc();
	f(a);	
	return 0;
}
