#include <stdio.h>

int main (void)
{
	// On définit la variable
	int nbr = 0;

	// On demande l'entrée à l'utilisateur
	printf("Entrez un entier : ");
	scanf("%d", &nbr);

	// On affiche la parité avec un ternaire
	printf(nbr % 2 == 0 ? "%d est pair\n" : "%d est impair\n", nbr);

	return 0;
}
