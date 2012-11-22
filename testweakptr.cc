#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <iostream>

int main()
{
	boost::shared_ptr<int> sp(new int(9));
	boost::weak_ptr<int> wp(sp);
	
	boost::shared_ptr<int> sp1 = wp.lock();
	
	sp.reset();
	if (sp1) {
		std::cout << "value = " << *sp1 << std::endl;
	} else {
		std::cout << "no value\n";
	}
	if (sp) {
		std::cout << "value = " << *sp << std::endl;
	} else {
		std::cout << "no value for sp\n";
	}
	return 0;
}

