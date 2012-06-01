#include <iostream>


int main()
{
	int a[] = {1, 2, 3};
	int (*pa)[3] = &a;
	printf("a[1] = %d\n", (*pa)[2]);
	return 0;
}
