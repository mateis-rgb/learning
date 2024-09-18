#include <stdio.h>

int main (void)
{
	// On déclare la variable année
	int year = 0;

	// On demande la saisie de l'utilisateur
	printf("Annee : ");
	scanf("%d", &year);

	// On test et on affiche l'année si elle est bissextile (soit multiple de 4 mais pas multiple de 100 ou 400)
	if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
	{
		printf("%d est une annee bissextile.\n", year);
	}
	else 
	{
		printf("%d n'est pas une annee bissextile.\n", year);
	}

	printf("Voici ttes les annes bissextiles de 1900 jusqu'a 3000\n");

	year = 1900;

	while (year <= 3000)
	{
		printf("%d\n", year);

		year+=4;
	}

	return 0;
}
