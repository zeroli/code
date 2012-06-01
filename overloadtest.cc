#include <iostream>

void f(int i)
{
	std::cout << i << std::endl;
}

int f(int i)
{
	return i;
}

int main()
{
	int i = 0;
	f(i);
	i = f(i);
	return 0;
}

