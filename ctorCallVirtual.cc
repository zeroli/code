/*
 * if base class call one virtual function in its ctor,
 * and derived class also reimplement this virtual function
 * in base::ctor, base virtual function will be called.
 *
 */
#include <iostream>

class base {
public:
	base()
	{	// base class will call base::call_virtual(). by zero 
		call_virtual();
	}
	virtual ~base()
	{ }

protected:
	virtual void call_virtual()   // = 0;   => ctor can not call pure virtual function
	#if 1
	{
		std::cout << "call base::call_virtual().\n";
	}
	#endif 
};

class derived : public base  {
public:
	derived() 
	{}
	~derived()
	{}
protected:
	virtual void call_virtual()
	{
		std::cout << "call derived::call_virtual().\n";
	}
};

int main()
{
	derived d;
	
	return 0;
}
		
