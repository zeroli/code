#include <iostream>

class base {
public:
	typedef void (base::*pfun)(void);

	base() { m_pfun = static_cast<pfun>(&base::doSomething); }
	~base() {}
	
	void hello(void) {
		std::cout << "Hello world.\n";
		(this->*m_pfun)();
	}
protected:
	void doSomething(void) { }

	pfun m_pfun;
};

class derived : public base {
public:
	derived() { m_pfun = static_cast<pfun>(&derived::do_other); }

	void do_other() {
		std::cout << "do other in derived.\n";
	}
};

int main()
{
	base* b = new derived();
	b->hello();
	delete b;
	return 0;
}
