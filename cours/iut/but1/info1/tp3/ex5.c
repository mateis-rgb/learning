#include <stdio.h>

/**
 * @brief Return the result of power between U, and I.
 * 
 * @param U 
 * @param I 
 * @return float 
 */
float puissanceWatt (float U, float I);

int main (void)
{
	// On déclare la variable
	float u_temp = 0;
	float i_temp = 0;

	// On demande l'entrée de l'utilisateur
	printf("Entrez la tension (en V) : ");
	scanf("%f", &u_temp);

	printf("Entrez le courant (en A) : ");
	scanf("%f", &i_temp);

	// On affiche le résultat
	printf("La puissance est de %.2f Watts", puissanceWatt(u_temp, i_temp));

	return 0;
}

float puissanceWatt (float U, float I)
{
	// On retourne le résultat
	return U * I;
}
