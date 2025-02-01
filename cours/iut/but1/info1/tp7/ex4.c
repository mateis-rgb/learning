#include <stdio.h>
#include <string.h>

char strSearch (const char * s, char ch);

char checkEmail (const char * email);


int main (void)
{
	char * email;

	printf("Entrez votre email : ");
	fgets(email, 255, stdin);

	switch (checkEmail(email))	
	{
		case 0:
			printf("L'adresse %s est valide.", email);	
			break;

		case 3:
			printf("L'adresse %s ne contient pas de point (.)", email);
			break;

		case 2:
			printf("L'adresse %s contient des espaces", email);
			break;

		case 1:
			printf("L'adresse %s ne contient pas d'arobas (@)", email);
			break;
	}

	return 0;
}


char strSearch (const char * s, char ch)
{
	unsigned long k = 0;
	char founded = -1;

	for (k = 0; k < strlen(s); k++)
	{
		if (s[k] == ch) founded = 1;
	}

	return founded;
}


char checkEmail (const char * email)
{
	if (strSearch(email, '@') == -1) return 1;
	
	if (strSearch(email, '.') == -1) return 2;
	
	if (strSearch(email, ' ') == 1) return 3;
	
	return 0;
}
