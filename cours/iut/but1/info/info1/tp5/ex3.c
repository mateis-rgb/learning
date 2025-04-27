#include <stdio.h>

int main (void)
{
	// On definit la variable
	float moy = 0;

	// On demande une entree par l'utilisateur
	printf("Entrez la moyenne : ");
	scanf("%f", &moy);

	// On gère les différents cas en fonction de la moyenne
	if (moy >= 0 && moy < 10)
	{
		printf("Vous etes recale.\n");
	}
	else if (moy < 12)
	{
		printf("Vous n'avez pas de mentions.\n");
	}
	else if (moy < 14) 
	{
		printf("Vous avez la mention assez bien.\n");
	}
	else if (moy < 16)
	{
		printf("Vous avez la mention bien.\n");
	}
	else if (moy <= 20)
	{
		printf("Vous avez la mention tres bien.\n");
	}

	return 0;
}
