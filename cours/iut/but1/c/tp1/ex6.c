#include <stdio.h>

int main (void)
{
	// On définit les variables (1 int, 3 float)
	int ohm = 0;
	float amp = 0, volt = 0, watt = 0;

	// On demande les entrées a l'utilisateur
	printf("Resistance en Ohms : ");
	scanf("%d", &ohm);

	printf("Courant en Amperes : ");
	scanf("%f", &amp);

	// On effectu les calculs
	volt = ohm * amp;
	watt = volt * amp;

	// On affiche les valeurs
	printf("U = %f Volts\n", volt);
	printf("P = %f Watts", watt);

	return 0;
}
