#include <stdio.h>

int main (void)
{
	int nbr = 0;
	int k = 2;

	printf("Entrez un nombre strictement positif : ");
	scanf("%d", &nbr);

	while (k < nbr)
	{
		if (k == 1)
		

		printf("%d est un diviseur de %d", k, nbr);

		k++;
	}

	return 0;
}
