#include <stdio.h>

int main (void)
{
	// On définit le U(0) de la suite
	int U = 1;

	// On fait un affichage en dur
	printf("U(0) = 1\n");

	// On fait une boucle while
	while (U < 1024)
	{
		// On affiche la suite 
		printf("U(%d) = %d\n", U, 2 * U);

		// On calcule le terme suivant
		U *= 2;
	}

	return 0;
}
