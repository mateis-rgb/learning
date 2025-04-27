#include <stdio.h>

int main (void)
{
	// On définit les variables
	float masse = 0, taille = 0, imc = 0;

	// On demande les entrées à l'utilisateur
	printf("Quel est votre poid en kilogrammes : ");
	scanf("%f", &masse);

	printf("Quelle est votre taille en metres : ");
	scanf("%f", &taille);

	// On calcule l'imc
	imc = masse / (taille * taille);

	// On affiche l'imc
	printf("Votre IMC est de %.1f kg/m^2", imc);

	return 0;
}
