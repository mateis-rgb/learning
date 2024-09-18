#include <stdio.h>

int main (void)
{
	// On définit les variables
	int nbr = 0;
	int k = 2;
	short hasDivider = 0; // On définit une variable (booléenne) qui permet de gérer le cas ou le nombre n'as pas de diviseur

	// On demande la saisie de l'utilisateur
	printf("Entrez un nombre strictement positif : ");
	scanf("%d", &nbr);

	// Tant que le compteur est strictement inferieur à l'entrée de l'utilisateur
	while (k < nbr)
	{
		// Tout les nombres sont divisibles par 1 donc pas interessant de le notifier
		if (k != 1)
		{
			// On regarde la divisibilité du nombre entré par rapport à tt les autres nombres
			if (nbr % k == 0)
			{
				// S'il y a au moins un diviseur
				hasDivider = 1;

				// On fait l'affichage
				printf("%d est un diviseur de %d\n", k, nbr);
			}
		}
		// On incrémente le compteur
		k++;
	}

	// Gestion du cas où il n'y a pas de diviseurs
	if (hasDivider == 0) printf("%d n'as pas de diviseurs.\n", nbr);

	return 0;
}
