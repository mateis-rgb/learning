#include <stdio.h>

/* Prototypage de la fonction qui récupère la longueur d'un entier
* @var {int} n
* @returns {int}
*/
int get_int_length (int n);

int main (void)
{
	// définition des fonctions
	int nbr = 0;
	int nbr_length = 0;

	// Demande de l'entrée à l'utilisateur
	printf("Entrez un entier : ");
	scanf("%d", &nbr);

	// On récupère la longueur de l'entier
	nbr_length = get_int_length(nbr);

	// On affiche une première ligne
	for (int k = 0; k <= nbr_length + 4; k++) printf("*");
	printf("\n* %d *\n", nbr);
	for (int k = 0; k <= nbr_length + 4; k++) printf("*");

	// On fait un retour à la ligne pour le retour en console
	printf("\n");

	return 0;
}

int get_int_length (int n)
{
	if (n < 10) return 0;

	return 1 + get_int_length(n/10);
}
