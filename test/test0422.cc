#include <iostream>
#include <list>
#include <set>

using namespace std;

void print_set(const set<int>& s)
{
	set<int>::const_iterator it = s.begin();
	for (; it!=s.end(); ++it) 
		std::cout << *it << " ";
	std::cout << std::endl;
}

void print_list(const list<int>& l)
{
	list<int>::const_iterator it = l.begin();
	for (; it!=l.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	int a = 10, b = 9, c = 8, d=7;
	if (a>b && c > d) {
		std::cout << "pass" << std::endl;
	} else {
		std::cout << "fail" << std::endl;
	}
	return 0;
	std::cout << "size of one char in c++: " << sizeof('a') << std::endl;
	list<int> l1, l2;
	l1.push_back(1); l1.push_back(2); l1.push_back(3);
	l1.push_back(4); l1.push_back(5); l1.push_back(6);
	l2.push_back(1); l2.push_back(3); l2.push_back(4);
	l2.push_back(6); l2.push_back(7); l2.push_back(8);

	set<int> s1;
	s1.insert(l1.begin(), l1.end());
	std::cout << "list 1 elements: \n";
	print_list(l1);
	std::cout << "insert them to s1:\n";
	print_set(s1);

	s1.insert(l2.begin(), l2.end());
	std::cout << "list 2 elements:\n";
	print_list(l2);
	std::cout << "insert them to s2:\n";
	print_set(s1);

	return 0;
}
