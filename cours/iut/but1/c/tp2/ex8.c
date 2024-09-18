#include <stdio.h>

int main (void)
{
	// On définit le U(0) de la suite
	int U = 1;
	int k = 0;

	// On fait une boucle while
	while (U < 1024)
	{
		// On affiche la suite 
		printf("U(%d) = %d\n", k, 2 * U);

		// On calcule le terme suivant et on met a jour le compteur
		U *= 2;
		k++;
	}

	return 0;
}
