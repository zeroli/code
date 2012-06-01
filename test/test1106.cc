#include <iostream>

class base {
public:
	virtual ~base() = 0;
};
base::~base() { }

class derived : public base
{
public:
};

int main()
{
	derived d;
	return 0;
}
