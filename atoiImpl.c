#include <stdio.h>
#include <stdlib.h>

int atoi_impl(char* s)
{
	char* p = s;
	if (s&&(*s=='-'||*s=='+'))
		++p;
	int ret = 0;
	while (p && *p!='\0') {
		if (*p<='9' && *p >= '0') {
			ret = 10*ret+(int)(*p-'0');	
			++p;
		} 
		else
			break;		
	}
	return (s&&*s=='-')? -1*ret : ret;
}

int main()
{
	char s[] = "+23a13a";
	printf("%s string is %d (std result: %d)\n", s, atoi_impl(s), atoi(s));
	return 0;
}
