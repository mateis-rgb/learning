#include <stdio.h>
#include <math.h>

int main (void)
{
	int e = 0;
	int U = 0;
	int i = 0;

	do
	{
		printf("Entrez un nombre entier strictement positif: ");
		scanf("%d", &e);
	} 
	while (e < 0);
	
	U = e;

	printf("\nLes valeurs de la suite de Syracuse sont :\n");

	while (U > 1)
	{
		printf("U(%d) = %d\n", i, U);
		i++;

		if (U % 2 == 0)
		{
			U = U/2;
		}
		else
		{
			U = 3 * U + 1;
		}
	}

	return 0;
}
