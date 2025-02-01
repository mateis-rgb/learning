#include <stdio.h>

/**
 * @brief Return the pow of a by n;
 * 
 * @param a 
 * @param n 
 * @return int 
 */
int puissance (int a, int n);

int main(void)
{
	// On affiche le cube des chiffres de 1 à 10.
	for (int k = 10; k > 0; k--) printf("%d au cube = %d\n", k, puissance(k,3));

	return 0;
}

int puissance (int a, int n)
{
	// On définit le cas de base à 1
	if (n == 0) return 1;

	// On fait les appels récursifs.
	return a * puissance(a, n - 1);
}
