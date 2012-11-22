#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <boost/bind.hpp>

using namespace boost;

class Printer {
	static int icount;
public:	
	void print() {
		std::cout << icount++ << std::endl;
	}
};

int Printer::icount = 0;

int main()
{
	std::vector<Printer> vp;
	for (int i = 0; i < 5; i++) {
		vp.push_back(Printer());
	}
	std::cout << "std::mem_func test:\n";
	std::for_each(vp.begin(), vp.end(), std::mem_fun_ref(&Printer::print));
	
	std::cout << "\n";
	std::cout << "boost::bind test:\n";
	std::for_each(vp.begin(), vp.end(), boost::bind(&Printer::print, _1));

	typedef void (Printer::*func)();
	func f = &Printer::print;
	
	std::cout << "pure member func test:\n";
	//std::cout << f(vp[0]) << std::endl;
	
}

	
