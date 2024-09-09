#include <stdio.h>

int main (void)
{
	// On définir les variables
	float minutes = 0, secondes = 0, speed = 0;

	// On demande l'entrée à l'utilisateur
	printf("Entrez la vitesse en minute par kilometre : ");
	scanf("%f'%f", &minutes, &secondes);

	// On fait le calcule
	speed = 60 / (((minutes * 60) + secondes) / 60);

	// On affiche le résultat
	printf("%.0f'%.0f min/km = %.2f km/h", minutes, secondes, speed);

	return 0;
}
