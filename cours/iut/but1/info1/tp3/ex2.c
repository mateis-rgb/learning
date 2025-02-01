#include <stdio.h>

/**
 * @brief return max value between a and b, if they're equal, it will return a value. 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int max (int a, int b);

int main (void)
{
	// On déclare les variables
	int note1 = 0;
	int note2 = 0;

	// On demande les entrées de l'utilisateur
	printf("Entrez la premiere note : ");
	scanf("%d", &note1);

	printf("Entrez la deuxième note : ");
	scanf("%d", &note2);

	// On affiche le résultat
	printf("La meilleure note est %d", max(note1, note2));

	return 0;
}

int max (int a, int b)
{
	// On test si a > b ou si a == b
	if (a == b || a > b) return a;
	
	// Sinon on retourne b
	return b;
}
