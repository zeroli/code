#include <iostream>

struct cpp_obj {
public:
	cpp_obj()
	{
		std::cout << "ctor\n";
	}

	cpp_obj(const cpp_obj& c)
	{
		std::cout << "copy ctor\n";
	}

	cpp_obj& operator =(const cpp_obj& rhs)
	{
		std::cout << "operator =\n";
		return *this;
	}

	~cpp_obj()
	{
		std::cout << "dtor\n";
	}
};

cpp_obj return_test()
{
	cpp_obj b;
	std::cout << "before return\n";
	return b;
}

int main()
{
	cpp_obj n = return_test();
}

