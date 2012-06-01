#include <stdio.h>
#include <math.h>

void my_print(char* string);
void my_print2(char* string);

#define TRACE(var, fmt) \
	printf("TRACE: " #var " = " #fmt "\n", var)

union { int a; int b; } uval;

int main()
{
	uval.a = 10;
	printf("v.a = %d, v.b = %d\n", uval.a, uval.b);
	return 0;
	double eps = 1e-8;
	double cella2 = 0.176;
	double pixel = 0.028;
	double cella2p = cella2 / ceil((cella2 - eps) / pixel);
	TRACE(cella2p, %f);
	int cella2n = (int)rint(cella2 / cella2p);
	TRACE(cella2n, %d);

	int ia = 10;
	TRACE(ia, %d);
	printf("size of one char in c:%d\n", sizeof('a'));
	char a = -127;
	printf("%#x\n", a);
	unsigned char i = -1;
	printf("%#x\n", i);
	printf("%d\n", i%256);
	return 0;
	char my_string[] = "hello there";
	
	my_print(my_string);
	my_print2(my_string);
}

void my_print(char* string)
{
	printf("The string is %s\n", string);
}

void my_print2(char* string)
{
	char* string2;
	int size, i;
	size = strlen(string);
	string2 = (char*)malloc(size+1);
	for (i = 0; i < size; i++)
		string2[size-i] = string[i];
	string2[size+1] = '\0';
	printf("The string printed backward is %s\n", string2);
}

