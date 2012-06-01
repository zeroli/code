#include <iostream>

int a = 10;

class A {
public:
	A(int v) {
		printf("v = %d.\n", v);
	}
};

A bb(100);
static A aa(10);
int main()
{
	return 0;
}
