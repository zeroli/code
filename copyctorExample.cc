#include <iostream>

class A {
public:
	A() { 
		std::cout << "A.ctor()" << std::endl;
	}
	A(const A& other) {
		std::cout << "A.copyctor()" << std::endl;
	}
	A& operator =(const A& other) {
		std::cout << "A.op =() " << std::endl;
	}
}; 

class AA : public A
{
public:
	AA() {
		std::cout << "AA.ctor()" << std::endl;
	}
	AA(const AA& other)
	: A(other) {  // unless manually call, compiler will call A.ctor, instead of A.ctor
		std::cout << "AA.copyctor() " << std::endl;
	}
	AA& operator =(const AA& other) {
		std::cout << "AA.op =()" << std::endl;
	}
};

int main()
{
	AA aa;	// A.ctor => AA.ctor
	AA bb(aa);	// A.copyctor  => AA.copyctor
	aa = bb;	// AA.op =
	return 0;
}

