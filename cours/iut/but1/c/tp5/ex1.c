#include <stdio.h>

int main (void)
{
	// On déclare la variable
	int m = 0;

	// On demande la saisie de l'utilisateur
	printf("Saisir le numero du mois : ");
	scanf("%d", &m);

	// On switch case sur m de 1 à 12
	switch (m)
	{
	case 1:
		printf("Le mois de janvier compte 31 jours.\n");
		break;

	case 2:
		printf("Le mois de février compte 28 ou 29 jours.\n");
		break;

	case 3:
		printf("Le mois de mars compte 31 jours. \n");
		break;

	case 4:
		printf("Le mois d'avril compte 30 jours. \n");
		break;

	case 5:
		printf("Le mois de mai compte 31 jours. \n");
		break;

	case 6:
		printf("Le mois de juin compte 30 jours. \n");
		break;

	case 7:
		printf("Le mois de juillet compte 31 jours. \n");
		break;

	case 8:
		printf("Le mois de aout compte 31 jours. \n");
		break;

	case 9:
		printf("Le mois de septembre compte 30 jours. \n");
		break;

	case 10:
		printf("Le mois de octobre compte 31 jours. \n");
		break;

	case 11:
		printf("Le mois de novembre compte 30 jours. \n");
		break;

	case 12:
		printf("Le mois de decembre compte 31 jours. \n");
		break;
	
	// Si la saisie dépace 12
	default:
		printf("Ce mois n'existe pas...\n");

		break;
	}

	return 0;
}
