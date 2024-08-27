#include <stdio.h>

int factoriel (int nombre)
{
	return nombre * factoriel(nombre - 1);
}

int main ()
{
	int input;

	printf("Entrez une factoriel a calculer: ");
	scanf("%d", input);

	int fact = factoriel(input);

	printf("la factoriel calculee est: %d", fact);

	return 0;
}