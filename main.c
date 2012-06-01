#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

int main()
{	
	printf("FLT_RADIX=%f\n", FLT_RADIX);
	printf("%f\n", scalbn(11,2));
	return 0;
	int sum = 0, i = 0;
	char input[2];
	while (1) {
		sum = 0;
		scanf("%s", input);
		for (i = 0; input[i] != '\0'; i++) 
			sum = sum*10+input[i]-'0';
		printf("input = %d\n", sum);
	}
	return 0;
}

