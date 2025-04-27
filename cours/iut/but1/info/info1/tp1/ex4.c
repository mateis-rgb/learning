#include <stdio.h>

int main (void)
{
	// On définit 3 variables dont pi
	float rad = 0, deg = 0, pi = 3.1415;

	// On interroge l'utilisateur sur l'angle à convertir
	printf("Angle en radians : ");
	scanf("%f", &rad);

	// On fait la conversion
	deg = (360/(2*pi))*rad;

	// On affiche le résultat
	printf("%f radians = %f degres\n", rad, deg);

	return 0;
}
