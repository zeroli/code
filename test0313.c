#include <stdio.h>

int main()
{
	int a = 2;
	int b = 00;
	printf("result = %d\n", a^b<<2);

	int i = 0;
	int sum = 0;
	for(i=0;i<10;++i,sum+=i);
	printf("sum= %d\n", sum);	// 1+2+3...+10
	return 0;
}
