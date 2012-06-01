#include <stdio.h>
#include <ctype.h>

// version 1
void strcpy1(char* s, char* t)
{	
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0') {
		i++;
	}
}

// version 2
void strcpy2(char* s, char* t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}
		
// version 3
void strcpy3(char* s, char* t)
{
	while ((*s++ = *t++) != '\0')
		;
}

// version 4
void strcpy4(char* s, char* t)
{
	while ((*s++ = *t++))
		;
}

// version 1
int strcmp1(char* s, char* t)
{
	int i;
	for (i = 0; s[i]==t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i]-t[i];
}

// version 2
int strcmp2(char* s, char* t)
{
	for (; *s == *t; s++,t++)
		if (*s == '\0')
			return 0;
	return (*s - *t);
}

int atoi(char s[])
{
	int i, n, sign;
	// skip whitespaces
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i]=='-') ? (-1): (+1);
	
	if (s[i]=='+' || s[i]=='-')
		i++;

	for (n = 0; isdigit(s[i]); i++)
		n = 10*n + (s[i]-'0');
	return sign*n;
}

double atof(char s[])
{
	int i;
	double n, sign, m;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i]=='-') ? (-1.0) : (+1.0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0.; isdigit(s[i]); i++)
		n = 10.*n + (s[i]-'0');
	if (s[i++] == '.') {
		for (m = 0.1; isdigit(s[i]); i++, m*=0.1)
			n += m * (s[i]-'0');
	}
	return sign*n;
}	

int main()
{
	char s[] = "1201.23901adfanbg";
	printf("atof(\"%s\" => %f)\n", s, atof(s));
}

