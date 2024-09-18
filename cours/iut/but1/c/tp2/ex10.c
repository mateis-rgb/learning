#include <stdio.h>

int main (void)
{
	// On déclare la variable année
	int year = 0;

	// On demande la saisie de l'utilisateur
	printf("Annee : ");
	scanf("%d", &year);

	// On test et on affiche l'année si elle est bissextile (soit multiple de 4 ou 400)
	if (year % 4 == 0)
	{
		if (year % 400 && !(year % 100))
		{
			printf("%d est une annee bissextile.\n", year);
		}
	}
	else 
	{
		printf("%d n'est pas une annee bissextile.\n", year);
	}


	return 0;
}
