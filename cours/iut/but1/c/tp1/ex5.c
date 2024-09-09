#include <stdio.h>

int main (void)
{
	// On définit 2 variables
	float km = 0, mi = 0;

	// On interroge l'utilisateur sur la distance à convertir
	printf("Entrez la distance en kilometres : ");
	scanf("%f", &km);

	// On fait la conversion
	mi = km/1.609344;

	// On affiche le résultat avec deux chiffres après la virgules pour les km
	printf("%.2f km = %f mi", km, mi);

	return 0;
}
