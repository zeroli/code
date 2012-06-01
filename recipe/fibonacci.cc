#include <stdio.h>

unsigned int Fibonacci(unsigned int n)
{
	if (n==0 || n==1)
		return n;
	else
		return Fibonacci(n-1U)+Fibonacci(n-2U);
	
}

unsigned int Fibonacci2(unsigned int n)
{
	unsigned int result = 1;
	unsigned int previous = 0;
	for (unsigned int i = 2; i <= n; i++) {
		unsigned int sum = previous+result;
		previous = result;
		result = sum;
	}
	return result;
}

int main()
{
	printf("Recursive fibonacci result for 5: %u\n", Fibonacci(5));
	printf("non-recursive fibonacci result for 5: %u\n", Fibonacci2(5));

	return 0;
}

