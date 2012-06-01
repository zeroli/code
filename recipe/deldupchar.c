#include <stdio.h>
#include <string.h>

void deldupchar(char* s)
{
	char* i, *j;
	i = s; j = s+1;
	if (s && *s!='\0') {
		while (*j!='\0') {
			if (*i!=*j)
				*++i = *j;		
			j++;
		}
		*++i = '\0';
	}
}

int main()
{
	char s[] = "";
	printf("ori string is:\n%s\n", s);
	deldupchar(s);
	printf("after, string changed to be:\n%s\n", s);
	return 0;
}
