#include <stdio.h>

int main (void)
{
	// On définit les variables
	int longueur = 0, largeur = 0, perimetre = 0;

	// On demande les entrées à l'utilisateur
	printf("Entrez la largeur du rectangle : ");
	scanf("%d", &largeur);

	printf("Entrez la longueur du rectangle : ");
	scanf("%d", &longueur);

	// On calcule le perimètre
	perimetre = longueur * 2 + largeur * 2;

	// On affiche le perimètre
	printf("Le perimetre du rectangle est %d", perimetre);

	return 0;
}
