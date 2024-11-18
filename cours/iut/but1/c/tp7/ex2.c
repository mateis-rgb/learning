#include <stdio.h>
#include <string.h>

void majuscule (char str[]);

int main (void)
{
	char str [] = "Ce texte est a mettre en manjuscule.";

	majuscule(str);

	printf("%s\n", str);

	return 0;
}

void majuscule (char str[])
{
	int k = 0;

	for (k = 0; (unsigned long) k < strlen(str); k++)
	{
		if (str[k] >= 'a' && str[k] <= 'z')
		{
			str[k] = str[k] - 'a' + 'A';
		}
	}
}
