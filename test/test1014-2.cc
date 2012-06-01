#include <vector>

int main()
{
	std::vector<int> a(10, 1);
	std::vector<int>::const_reverse_iterator it = a.rbegin();
	for (; it!=a.rend(); it++)
		;
	return 0;
}
