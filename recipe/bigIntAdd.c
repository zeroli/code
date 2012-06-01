#include <stdio.h>
#include <string.h>
#define PRIN print("\n")

int flag = 0;
	
void change(char da[], char db[], int a[], int b[], int c[]) 
{
	int i;
	if (a[0] > b[0]) {
		for (i=1; i<=a[0]; a[i]=da[a[0]-i]-'0', i++)

