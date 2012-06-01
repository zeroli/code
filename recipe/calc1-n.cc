#include <iostream>

template <int N>
class Addition {
public:
	Addition() 
		: d_ret(0) {}
	long long operator()() {
		d_ret = Addition<N-1>()()+N;
		return d_ret;
	}
	
private:
	long long d_ret;
};

template <>
class Addition<1> {
public:
	Addition() {}
	long long operator()() {
		return 1;
	}
};

int main()
{
	const int N = 100;
	long long sum = Addition<N>()();
	std::cout << "Addition: 1+2+...+" << N << "\n";
	std::cout << "sum = " << sum << "\n";
	return 0;
}
