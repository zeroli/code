#include <stdio.h>

int main()
{
	int i;
	i = 10;
	printf("i : %d\n", i);
	printf("sizeof(i++) is : %d\n", sizeof(i++));
	printf("i : %d\n", i);

	int a = 1;
	switch (a) {
		char b = 'a';
		case 1:
			printf("b is %ld\n", b);
		default:
			printf("b is %ld\n", b);
			break;
	}
	return 0;
}

