#include <iostream>

template <typename T>
class Number;
template <typename T>
std::ostream& operator << (std::ostream& os, const Number<T>& n);
template <typename T>
std::istream& operator >> (std::istream& is, Number<T>& n);

template <typename T>
class Number {
public:
	Number(T a) 
		: val(a) {}
	~Number() {}
	const T& value() const {
		return val;
	}
	T& value() {
		return val;
	}
private:
	T val;
public:
	friend std::ostream& operator << <T>(std::ostream& os, const Number& n);
	friend std::istream& operator >> <T>(std::istream& is, Number& n);
	friend Number& operator += (Number& A, const Number& B) {
		A.val += B.val;
		return A;	
	}
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Number<T>& n)
{
	os << n.val << std::endl;
	return os;
}

template <typename T>
std::istream& operator >> (std::istream& is, Number<T>& n)
{
	is >> n.val;
}

int main()
{
	Number<int> a(3);
	Number<int> b(4);
	b = (a += b);
	std::cout << a << b << std::endl;
	return 0;
}

