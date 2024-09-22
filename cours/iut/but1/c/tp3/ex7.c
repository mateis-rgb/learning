#include <stdio.h>
#include <math.h>

/**
 * @brief Return if n is a perfect square
 * 
 * @param n 
 * @return char 
 */
char isPerfectSquare (int n);

int main (void)
{
	// On déclare la variable
	int temp = 0;
	char isPerfect = 0;

	// On demande l'entrée de l'utilisateur
	printf("Entrez un entier : ");
	scanf("%d", &temp);

	// On contrôle si l'entier est carré parfait
	isPerfect = isPerfectSquare(temp); 

	// On affiche le résultat
	if (isPerfect) printf("%d est un carré parfait car %d = %.0f^2.\n", temp, temp, sqrtf(temp));
	else printf("%d n'est pas un carré parfait.\n", temp);

	printf("\n\n");

	for (int k = 316; k >= 0; k--)
	{
		printf("%d = %d x %d\n", k * k, k, k);
	}

	return 0;
}

char isPerfectSquare (int n)
{
	// On définit les variables
	int k = 0;
	char isPerfect = 0;

	// Tant que le carré parfait n'est pas trouvé ou que k < n
	while (k < n && isPerfect == 0)
	{
		// On regarde si le carré de k est égale à n
		if (k * k == n) isPerfect = 1;

		k++;
	}

	// On retourne le booleen 
	return isPerfect;
}
