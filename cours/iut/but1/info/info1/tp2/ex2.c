#include <stdio.h>

int main (void)
{
	// On définit la variable de moyenne
	float average;

	// On demande l'entrée à l'utilisateur
	printf("Entrez une moyenne : ");
	scanf("%f", &average);

	// On fait nos tests et nos affichages
	if (average >= 12) printf("Bravo ! Vous avez une mention.\n");
	else printf("Vous n'avez pas de mention.\n");

	return 0;
}
