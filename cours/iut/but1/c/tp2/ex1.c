#include <stdio.h>

int main (void)
{
	// On définit les variables nécessaires
	int a = 0;
	int b = 0;

	// On demande à l'utilisateur
	printf("Valeur de a : ");
	scanf("%d", &a);

	printf("Valeur de b : ");
	scanf("%d", &b);

	// Version 1 - On utilise un opérateur ternaire 
	// printf("La plus grande valeur est ");
	// printf(a < b ? "b\n" : "a\n");

	// Version 2 - On utilise un double opérateur ternaire
	// printf("La plus grande valeur est ");
	// printf(a < b ? "b = %d\n" : "a = %d\n", a < b ? b : a);

	// Version 3
	// On fait le contrôle si les deux nombres sont égaux
	if (a == b)
	{
		printf("Les deux valeurs a=%d et b=%d sont égales", a, b);
	}
	// Sinon on utilise l'affichage de la version 2
	else printf(a < b ? "b = %d\n" : "a = %d\n", a < b ? b : a);

	return 0;
}
