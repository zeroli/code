#include <iostream>

int main()
{
	int* p1 = new int[10];
	for (int i = 0; i < 10; i++, p1++) 
		std::cout << *p1 << " ";
	std::cout << std::endl;
	int* p2 = new int[10]();
	for (int i = 0; i < 10; i++, p2++)
		std::cout << *p2 << " ";
	std::cout << std::endl;
	{
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = (int*)(p);
	p1++;
	p = (char*)(p1);
	printf("result is %s\n",p);
	}
	return 0;
}
