#include <iostream>

template <typename T>
void testTemplate(T a)
{
	static int test_static = 1;
	std::cout << "test_static: " << test_static << " => a: " << a << std::endl;
	test_static++;
}

template <typename T>
class classA {
	static T a;
};

template <typename T> 
T classA<T>::a = 1;

int main()
{
	// each template function instance has one static member copy
	testTemplate(1);
	testTemplate(2.0);
	return 0;
}
