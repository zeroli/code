#include <iostream>

#define TRACE(VAR, FMT) \
	printf("TRACE: " #VAR " = " #FMT "\n", VAR);

int main()
{
	printf("sizeof ('a') = %d\n", sizeof('a'));
	int ia = 10;
	TRACE(ia, %d);
	
	printf("%*d\n", ia, ia);
	return 0;
}

