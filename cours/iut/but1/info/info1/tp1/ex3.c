#include <stdio.h>

int main (void)
{
	// On défini la variable x
	int x = 0;

	// On affecte la variable
	x = 12;

	// On affiche la valeur de x
	printf("a. x = %d\n\n", x);

	// On demande une entrée à l'utilisateur
	printf("b. Entrez un entier : ");
	scanf("%d", &x);
	
	// On l'affiche
	printf("x = %d\n\n", x);
	
	// On demande à nouveau une entrée à l'utilisateur
	printf("c. Entrez un entier : ");
	scanf("%d", &x);

	// On affiche le carrer de l'entrée
	printf("x au carrer = %d", x*x);

	return 0;
}
