#include <stdio.h>

int main (void)
{
	// On définit la variable
	int color_code = 0;

	// On demande l'entrée à l'utilisateur
	printf("Entrez un chiffre : ");
	scanf("%d", &color_code);

	// On fait un switch-case pour afficher dynamiquement la couleur en fonction du code couleur
	switch (color_code)
	{
		case 0:
			printf("%d correspond au code couleur noir.\n", color_code);
			break;

		case 1:
			printf("%d correspond au code couleur marron.\n", color_code);
			break;

		case 2:
			printf("%d correspond au code couleur rouge.\n", color_code);
			break;

		case 3:
			printf("%d correspond au code couleur orange.\n", color_code);
			break;

		case 4:
			printf("%d correspond au code couleur jaune.\n", color_code);
			break;

		case 5:
			printf("%d correspond au code couleur vert.\n", color_code);
			break;

		case 6:
			printf("%d correspond au code couleur bleu.\n", color_code);
			break;
	
		case 7:
			printf("%d correspond au code couleur violet.\n", color_code);
			break;
	
		case 8:
			printf("%d correspond au code couleur gris.\n", color_code);
			break;
	
		case 9:
			printf("%d correspond au code couleur blanc.\n", color_code);
			break;
	}

	return 0;
}
