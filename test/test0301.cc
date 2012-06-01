#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a;
	a.push_back(1);
	a.pop_back();
	a.pop_back();
	if (a.empty()) 
		std::cout << "a is now empty\n";
	else
		std::cout << "a is not empty\n";
	return 0;
}
