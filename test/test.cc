#include <iostream>

struct A 
{
	A() { std::cout << "Construct A.\n"; }
	~A() { std::cout << "Destruct A.\n"; }
};

void enterA() 
{
	{
	static A a;
	std::cout << "enterA function call.\n";
	}
}

void enterB()
{
	{
	static A b;
	std::cout << "enterB function call.\n";
	}
}

void enterC()
{
	{
	static A c;
	std::cout << "enterC function call.\n";
	}
}

int main()
{
/*
	enterA();
	enterB();
	enterC();
*/
	const unsigned char c2h[] = "0123456789ABCDEF";
	for (int i = 0; i < sizeof(c2h)/sizeof(unsigned char)-1; i++)
		std::cout << "'" << c2h[i] << "'" << " => " << int(c2h[i]) << std::endl;			
	return 0;
}
