#include <iostream>

class Base1 {
public:
	virtual void f() { 
		std::cout << "Base1::f" << std::endl;
	}
	virtual void g() {
		std::cout << "Base1::g" << std::endl;
	}
	virtual void h() {
		std::cout << "Base1::h" << std::endl;
	}
};

class Base2 {
public:
	virtual void f() {
		std::cout << "Base2::f" << std::endl;
	}
	virtual void g() {
		std::cout << "Base2::g" << std::endl;
	}
	virtual void h() {
		std::cout << "Base2::h" << std::endl;
	}
};

class Base3 {
public:
	virtual void f() {
		std::cout << "Base3::f" << std::endl;
	}
	virtual void g() {
		std::cout << "Base3::g" << std::endl;
	}
	virtual void h() {
		std::cout << "Base3::h" << std::endl;
	}
};

class Derive : public Base1, public Base2, public Base3
{
public:
	virtual void f() { 
		std::cout << "Derive:f" << std::endl;
	}
	virtual void g1() {
		std::cout << "Derive::g1" << std::endl;
	}
};

typedef void (*Fun)(void);

int main()
{
	Fun pfun = 0;

	Derive d;
	ptrdiff_t** pVtab = (ptrdiff_t**)&d;

	pfun = (Fun)pVtab[0][0];
	pfun();

	pfun = (Fun)pVtab[0][1];
	pfun();

	pfun = (Fun)pVtab[0][2];
	pfun();

	pfun = (Fun)pVtab[0][3];
	pfun();


	// base2
	pfun = (Fun)pVtab[1][0];
	pfun();

	pfun = (Fun)pVtab[1][1];
	pfun();

	pfun = (Fun)pVtab[1][2];
	pfun();


	// base3
	pfun = (Fun)pVtab[2][0];
	pfun();
	
	pfun = (Fun)pVtab[2][1];
	pfun();

	pfun = (Fun)pVtab[2][2];
	pfun();

	pfun = (Fun)pVtab[2][3];
	std::cout << pfun << std::endl;

	return 0;
}
