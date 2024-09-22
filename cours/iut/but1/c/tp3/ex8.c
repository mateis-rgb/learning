#include <stdio.h>

/**
 * @brief the product of an integer and all the integers below it
 * 
 * @param n 
 * @return int 
 */
int factorielle (int n);

int main (void)
{
	// On affiche la factorielle de 5 à 0
	for (int k = 5; k >= 0; k--) printf("%d! = %d\n", k, factorielle(k));

	return 0;
}

int factorielle (int n)
{
	// Cas de base, si n <= 0, on retourne 1
	if (n <= 0) return 1;

	// On retourne le produit de n * n-1 * n-2 * 1
	return n * factorielle(n - 1);
}
