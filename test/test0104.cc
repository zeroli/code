#include <iostream>
#include <string>

class Rational 
{
	friend Rational operator + (const Rational& aa, const Rational& bb);
public:
	explicit Rational(int a = 0, int b = 0) 
	: d_a(a), d_b(b) { }
	
	
private:
	int d_a;
	int d_b;
};

Rational operator +(const Rational& aa, const Rational& bb)
{
	Rational tmp;
	tmp.d_a += aa.d_a;
	tmp.d_b += aa.d_b;
	return tmp;
}

int main()
{
	Rational r;
	Rational aa(1, 2), bb(2, 3);
	r = aa + bb;

	const double dd = 2.;
	double dd1 = 0.;
	dd1 = dd;

	const std::string str1("AA");
	std::string str2(str1);
	str2 = str1;
	return 0;
}
