#include <stdio.h>

unsigned char notInString (unsigned char value, unsigned char* string);

int add (int a, int b);

int sub (int a, int b);

int mul (int a, int b);

int div (int a, int b);


int main (void)
{
	unsigned char choice = 0;
	
	printf("Calculatrice Basique.\n\n");

	do
	{
		printf("Entrez le signe du calcul (+ - * /) : ");

	} while (choice );
	
	

	return 0;
}


unsigned char notInString (unsigned char value, unsigned char* string)
{	
	unsigned char k = 0;
	unsigned char founded = 0;

	while ((string[k] != '\0') || (k < 254))
	{
		if (string[k] == value)
		{
			founded = 1;
		}

		k++;
	}

	return founded;
}


int add (int a, int b)
{
	return a + b;
}


int sub (int a, int b)
{
	return a - b;
}


int mul (int a, int b)
{
	return a * b;
}


int div (int a, int b)
{
	return a / b;
}
