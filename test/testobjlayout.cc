#include <iostream>

class Parent {
public:
	int iparent;
	Parent() 
	: iparent(10) {}

	virtual void f() { 
		std::cout << "Parent::f()" << std::endl;
	}
	virtual void g() {
		std::cout << "Parent::g()" << std::endl;
	}
	virtual void h() {
		std::cout << "Parent::h()" << std::endl;
	}
};

class Child : public Parent {
public:
	int ichild;
	Child() 
	: ichild(100) { }

	virtual void f() {
		std::cout << "Child::f()" << std::endl;
	}
	virtual void g_child() {
		std::cout << "Child::g_child()" << std::endl;
	}
	virtual void h_child() {
		std::cout << "Child::h_child()" << std::endl;
	}
};

class GrandChild : public Child {
public:
	int igrandchild;
	GrandChild()
	: igrandchild(1000) { }
	virtual void f() { 
		std::cout << "GrandChild::f()" << std::endl;
	}
	virtual void g_child() {
		std::cout << "GrandChild::g_child()" << std::endl;
	}
	virtual void h_grandchild() {
		std::cout << "GrandChild::h_grandchild()" << std::endl;
	}
};

typedef void (*Fun)(void);

int main() 
{
	Fun pfun;
	GrandChild gc;
	ptrdiff_t** pvtab = (ptrdiff_t**)&gc;
	std::cout << "[0] GrandChild::_vptr->" << std::endl;
	for (int i = 0; (Fun)pvtab[0][i]!=NULL; i++) {
		pfun = (Fun)pvtab[0][i];
		std::cout << "    [" << i << "] ";
		pfun();
	}
	std::cout << "&obj = " << (int64_t)((ptrdiff_t*)&gc) << std::endl;
	std::cout << "&obj+1=" << (int64_t)((ptrdiff_t*)&gc+1) << std::endl;
	int* p = (int*)((ptrdiff_t*)&gc+1);
	std::cout <<"[1] Parent.iparent = " << (int)p[0] << std::endl;
	std::cout <<"[2] Child.ichild = " << (int)p[1] << std::endl;
	std::cout <<"[3] GrandChild.igrandchild = " << (int)p[2] << std::endl;
	return 0;
}
