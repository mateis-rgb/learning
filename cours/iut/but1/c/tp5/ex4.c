#include <stdio.h>

int main (void)
{
	// On definir la variable
	int percent = -1;
	
	// On demande l'entrée de l'utilisateur
	printf("Entrez le pourcentage : ");
	scanf("%d", &percent);

	// On boucle tant que l'utilisateur ne rentre pas un pourcentage valide
	do
	{
		// On demande l'entrée de l'utilisateur
		printf("Veuillez entrer un pourcentage compris entre 0 et 100 : ");
		scanf("%d", &percent);
	}
	while (percent < 0 || percent > 100);

	// On affiche le pourcentage valide
	printf("Vous avez entre %d%%", percent);
	
	return 0;
}
