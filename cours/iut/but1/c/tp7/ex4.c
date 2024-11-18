#include <stdio.h>
#include <string.h>


char strSearch (const char * s, char ch);


int main (void)
{

	return 0;
}


char strSearch (const char * s, char ch)
{
	int k = 0;
	char founded = -1;

	for (k = 0; k < strlen(s); k++)
	{
		if (s[k] == ch) founded = 1;
	}

	return founded;
}
