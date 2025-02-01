#include <stdio.h>

/**
 * @brief Convert celcius to fahrenheit
 * 
 * @param C 
 * @return float 
 */
float cel2Far (float C);

int main (void)
{
	// On déclare la variable
	float cel = 0;

	// On demande l'entrée de l'utilisateur
	printf("Entrez la temperature en °C : ");
	scanf("%f", &cel);

	// On affiche le résultat
	printf("%.1f°C = %.0f°F", cel, cel2Far(cel));

	return 0;
}

float cel2Far (float C)
{
	// On retourne le résultat
	return (C * 9 / 5) + 32;
}
