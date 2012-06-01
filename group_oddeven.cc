#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>

bool func(int n)
{
	return (n&1)==0;
}

void group_oddeven(std::vector<int>& a, bool (*func)(int))
{
	int i = 0, j = a.size()-1;
	int buf = 0;
	while (i < j) {
		printf("a[%d]=%d, a[%d]=%d\n", i, a[i], j, a[j]);
		if (!func(a[i]))	// odd, move forward
		{	i++; continue; }
		if (func(a[j]))		// even, move backward
		{	j--; continue; }
		
		std::swap(a[i++], a[j--]);
	}
}

int main()
{
	srand(time(0));	
	std::vector<int> a;
	for (int i = 0; i < 20; i++)
		a.push_back((int)rand()%100);
	std::cout << "orginal random number array is:\n";
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	
	group_oddeven(a, func);
	std::cout << "after group to odd(left), and even(right), the array is :\n";
	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	return 0;
}
