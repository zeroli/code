#include <stdio.h>
#include <string.h>

void revertString(char* s)
{
	int len = 0;
	int i = 0;
	char tmp;
	len = strlen(s);
	printf("length of string is : %d\n", len);
	for (i = 0; i < len/2; i++) {
		tmp = *(s+i);
		*(s+i) = *(s+len-i-1);
		*(s+len-i-1) = tmp;
	}
}

int main()
{
	char s[] = "SMO is a very successful product in Brion";
	printf("The original string is :\n%s\n", s);
	
	revertString(s);

	printf("After reverting in place, the string is :\n%s\n", s);
	return 0;
}	
