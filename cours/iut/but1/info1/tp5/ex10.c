#include <stdio.h>

/**
 * @brief Return 1 if a is divisible by b and 0 instead
 * 
 * @param a 
 * @param b 
 * @return char 
 */
char isDivider (int a, int b);

/**
 * @brief Find the littlest divider
 * 
 * @param n 
 * @return int 
 */
int littleDivider (int n);

/**
 * @brief Find if a num is prime, in the other case, returns little divider of it's number.
 * 
 * @param n 
 * @return int 
 */
int prime (int n);

int main (void)
{
	// Déclaration des variables
	int nbr = 0;
	char primed_nbr = 0;

	// Demande de l'entrée de l'utilisateur
	printf("Entrez un nombre entier : ");
	scanf("%d", &nbr);

	// Verification du nombre premier
	primed_nbr = prime(nbr);

	// Affichage en fonction du nombre premier
	if (primed_nbr == 0) printf("%d est un nombre premier.", nbr);
	else printf("%d est divisible par %d, ce n'est pas un nombre premier.", nbr, primed_nbr);

	return 0;
}

char isDivider (int a, int b)
{
	// On teste si le nombre a est divisble par le nombre b
	if (a % b == 0) return 1;

	// Sinon on revoit faux
	return 0;
}

int littleDivider (int n)
{
	// On déclare les variables
	int k = 2;
	int foundedValue = -1;

	// On boucle tant qu'un diviseur n'a pas été trouvé ou que le compteur dépasse le nombre
	while (foundedValue == -1 && k < n)
	{
		// On check si un diviseur existe et on le stocke dans une variable
		if (isDivider(n, k))
		{
			foundedValue = k;
		}

		k++;
	}

	// On retourne la valeur trouvé ou -1 le cas échéant
	return foundedValue;
}

int prime (int n)
{
	// On stock si un diviseur est trouvé dans une variable
	int divider = littleDivider(n);

	if (n == 1 || n == 0) return n;

	// On retourne la valeur du plus petit diviseur s'il est différent de -1, et 0 le cas échéant.
	return divider != -1 ? divider : 0;
}
