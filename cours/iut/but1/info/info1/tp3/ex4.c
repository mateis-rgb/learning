#include <stdio.h>

/**
 * @brief Return 0 if n is not even, 1 in the other case
 * 
 * @param n 
 * @return char 
 */
char isEven (int n);

int main (void)
{
	// On déclare la variable
	int x = 0;

	do {
		// On demande l'entrée de l'utilisateur
		printf("Entrez un entier : ");
		scanf("%d", &x);

		// On affiche le résultat
		printf("%d est ", x);

		// On affiche pair ou impair en fonction du résultat de la fonction
		if (isEven(x)) printf("pair\n");
		else printf("impair\n");
	} 
	// On arrète si x == 0
	while (x != 0);

	return 0;
}

char isEven (int n)
{
	// On retourne 1 si n est pair, sinon 0
	return (n % 2) == 0;
}
