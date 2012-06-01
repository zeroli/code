#include <iostream>
#include <cstdio>
#include <vector>

char* getmemory()
{
	char p[] = "Hello world\n";
	return p;
}

class Base 
{
public:
	Base() { Init(); }
	virtual void Init() { printf("BaseInit\n"); }
	virtual void func() { printf("Base func\n"); }
};

class Derived: public Base
{
public:
	virtual void Init() { printf("DerivedInit\n"); }
	void func() { printf("Derived func\n"); }
};

struct A
{
	A() { printf("A"); }
	~A() { printf("~A"); }
};

struct B
{
	B() { printf("B"); }
	~B() { printf("~B"); }
};

struct C
{
	C() { printf("C"); }
	~C() { printf("~C"); }
};

struct D
{
	D() { printf("D"); }
	~D() { printf("~D"); }
};

struct E
{
	E() { printf("E"); }
	~E() { printf("~E"); }
};

void printHex(char* p)
{
	long long val = 0L;
	while (p&&*p!='\0') {
		val = 10*val+*p-'0';
		p++;
	}
	printf("val = %u\n", val);
	std::vector<char> vhexs;
	long long k=0;
	while (k = (val >> 4)) {
		vhexs.push_back(char(val-16*k));
		val = k;
	}
	vhexs.push_back(char(val));
	static char hextable[] = "0123456789ABCDEF";
	for (int i = vhexs.size()-1; i >=0; i--)
		printf("%c", hextable[vhexs[i]]);
	printf("\nHEX=");
	#if 0
	for (std::vector<char>::const_reverse_iterator lit = vhexs.rbegin();
		lit != vhexs.rend(); ++lit)
		printf("%c", *lit);
	#endif
	printf("\n");
}

C c;
int main()
{
char* p = 0;
	p = getmemory();
	for (int i = 0; i < 12;i++)
		printf("%c", p[i]);
	printf("\n");


	A* pa = new A;
	B b;
	{ E e; }
	static D d;
	delete pa;

	printf("\n");
	char k[] = "123456789";
	printHex(k);
	return 0;
}
	
