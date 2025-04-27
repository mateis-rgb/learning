#include <stdio.h>

/**
 * @brief Calculate U in fact of n
 * 
 * @param n 
 * @return float 
 */
float U (int n);

int main (void)
{
	// Déclaration des variables
	int k = 0;
	float u = 1;

	// On lance U(k) tant qu'elle est supérieur à 0.01
	for (k = 0; 0.01 < u; k++)
	{
		u = U(k);
	}

	// On affiche le résultat
	printf("u(n) <= 0.01 ? n = %d\nU(%d) = %f\n", k, k, U(k));

	return 0;
}

float U (int n)
{
	// On déclare les variables
	float u = 1;
	int k = 1;

	// On calcule la suite jusqu'à n
	for (k = 1; k < n; k++)
	{
		u = u/(u+1);
	}

	return u;
}
