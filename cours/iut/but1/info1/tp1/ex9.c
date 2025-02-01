#include <stdio.h>
#include <math.h>

int main (void)
{
	// On définit les variables
	float rayon = 0, hauteur = 0, volume = 0;

	// On demande les entrées à l'utilisateur
	printf("Rayon du cylindre (cm) : ");
	scanf("%f", &rayon);

	printf("Hauteur du cyclindre (cm) : ");
	scanf("%f", &hauteur);

	// On calcule le volume
	volume = M_PI * (rayon * rayon) * hauteur;

	// On affiche l'imc
	printf("Le cylindre a un volume de %f litres.", volume);

	return 0;
}
