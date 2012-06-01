#include <iostream>
#include <cstdio>

int square(int n)
{
	int tmp = 0;
	for (int i = 1; i < n; i++) {
		tmp += 2*(i-1)+1;		
		if (tmp == n) 
			return i;
		continue;
	}
	if (n!=0) {
		printf("no integer sqare found!\n");
		tmp = -1;
	}
	return tmp;
}

int main()
{
	int n = 0;
	printf("please enter one positive number: \n");
	scanf("%d", &n);
	if (n<0) {
		fprintf(stderr, "invalid number!");
		exit(-1);
	}
	printf("sqrt(n)=%d\n", square(n));
	return 0;
}
	
