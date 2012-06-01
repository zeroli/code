template <typename T>
struct testClass {
	static int _data;
};

template <> int testClass<char>::_data = 1;
template <> int testClass<long>::_data = 2;

template <class I, class O> 
struct testClass {
	testClass() { 
		std::cout << "I, O" << std::endl;
	}
};

template <class T> 
struct testClass<T*, T*> {
	testClass() {
		std::cout << "T*, T*" << std::endl;
	}
};

template <class T> 
struct testClass<const T*, T*> {
	testClass() {
		std::cout << "const T*, T*" << std::endl;
	}
};

int main()
{
	testClass<int, char> obj1;
	testClass<int*, int*> obj2;
	testClass<const int*, int*> obj3;
}

template <class T> 
struct testClass {
	void swap(testClass&) {
		std::cout << "swap()" << std::endl;
	}
};

template <class T> inline void swap(testClass<T>& x, testClass<T>& y)
{
	x.swap(y);
}

struct testClass {
	template <class T> void mfun(const T& t)
	{
		std::cout << t << std::endl;
	}
	template <class T> operator T()
	{
		return T();
	}

};

template <class T> 
struct test {
	T a;
};

template <class I, class O=test<I> > 
struct testClass {
	I b;
	O c;
};

template <class T, int n> 
struct testClass {
	T _t;
	testClass() : _t(n) {
	}
};

template <class T> struct testClass;



	


