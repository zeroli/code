#include <stdio.h>
#include <string.h>

int myStrlen(char* s)
{
	if (*s!='\0') 
		return myStrlen(s+1)+1;
	else
		return 0;
}

int main()
{
	char s[] = "SMO is a good product in Brion";
	printf("string is \"%s\"\n", s);
	printf("string length is %d (std strlen=%d)\n", myStrlen(s), strlen(s));
	return 0;
}
