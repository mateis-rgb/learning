#include <stdio.h>

void saisie (int notes[], float durees[]);

void affichage (int notes[], float durees[]);


int main (void)
{
	int * notes;
	float * durees;

	return 0;
}


void saisie (int notes[], float durees[])
{
	int nTemp = 0;
	float dTemp = 0;

	int len = 0;

	printf("Saisissez un morceau : \n");

	do
	{
		printf("Frequence de la note (en Hz): ");
		scanf("%d", &nTemp);	

		if (nTemp > 0)
		{
			printf("Duree de la note (en sec): ");
			scanf("%f", &dTemp);

			if (dTemp > 0)
			{
				notes[len] = nTemp;
				durees[len] = dTemp;
			}
		}

		len++;
	} 
	while (nTemp < 0 || dTemp < 0);
	
	notes[len] = -1;
	durees[len] = -1;
}


void affichage (int notes[], float durees[])
{
	int len = 0;
	int k = 0;

	while (notes[len] != -1)
	{
		len++;
	}

	printf("Morceau: ");

	for(k = 0; k <= len; k++)
	{
		printf("%d(%.2f) ", notes[k], durees[k]);
	}
}
