#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>
#include <iterator>
#include <utility>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>
#include <iostream>

template <bool use_swap> struct iter_swap_impl;

template <class ForwardIterator1, class ForwardIterator2>
void my_iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
{
	typedef std::iterator_traits<ForwardIterator1> traits1;
	typedef typename traits1::value_type v1;
	typedef typename traits1::reference r1;

	typedef std::iterator_traits<ForwardIterator2> traits2;
	typedef typename traits2::value_type v2;
	typedef typename traits2::reference r2;

	bool const use_swap = boost::is_same<v1, v2>::value
						&& boost::is_reference<v1>::value
						&& boost::is_reference<v2>::value;
	
	iter_swap_impl<use_swap>::do_it(i1, i2);
}

template <>
struct iter_swap_impl<true>
{
	template <class ForwardIterator1, class FowardIterator2>
	static void do_it(ForwardIterator1 i1, FowardIterator2 i2)
	{
		std::swap(*i1, *i2);
	}
};

template <>
struct iter_swap_impl<false>
{
	template <class FowardIterator1, class FowardIterator2>
	static void do_it(FowardIterator1 i1, FowardIterator2 i2)
	{
		typename std::iterator_traits<FowardIterator1>::value_type
		tmp = *i1;
		*i1 = *i2;
		*i2 = tmp;
	}
};

int main()
{
	std::ostringstream outstr;
	std::vector<std::string> v1;
	for (int i = 0; i < 10; i++)
	{
		outstr.str("");
		outstr << "AAA" << i;
		v1.push_back(outstr.str());
	}
	
	std::copy(v1.begin(), v1.end(), std::ostream_iterator<std::string>(std::cout, ","));
	std::cout << "\n";

	std::list<std::string> l1;
	for (int i = 0; i < 20; i++)
	{
		outstr.str("");
		outstr << "BBB" << i;
		l1.push_back(outstr.str());
	}
	std::copy(l1.begin(), l1.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << "\n";
	
	std::vector<std::string>::iterator iv = v1.begin();
	std::list<std::string>::iterator il = l1.begin();
	for (; iv != v1.end() && il != l1.end(); ++iv, ++il)
	{
		my_iter_swap(iv, il);
	}
	std::cout << "\n";
	std::copy(v1.begin(), v1.end(), std::ostream_iterator<std::string>(std::cout, ","));
	std::cout << "\n";
	std::copy(l1.begin(), l1.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << "\n";
	return 0;
}	
	
