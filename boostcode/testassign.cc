#include <boost/assign/std/vector.hpp>
#include <boost/assert.hpp>
#include <boost/assign/list_inserter.hpp>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std;
using namespace boost::assign;

void test1()
{
	std::vector<int> values;
	values += 1,2,3,4,5,6,7,8,9;
	BOOST_ASSERT(values.size() == 9);
	BOOST_ASSERT(values[0] == 1);
	BOOST_ASSERT(values[8] == 9);
	std::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, ","));
	std::cout << "\n";
}

void test2()
{
	std::deque<int> di;
	push_front(di) = 1,2,3,4,5,6,7,8,9;
	std::copy(di.begin(), di.end(), std::ostream_iterator<int>(std::cout, ","));
	std::cout << "\n";
}
	
int main()
{
	test1();
	test2();

}

