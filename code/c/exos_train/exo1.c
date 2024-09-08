#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	La fonction retourne un nombre aléatoire entre 0 et le paramètre en entrée
	
	@var {int} max
	@return {int}
*/
int randint (int max);

int main (void)
{
	// Tirage aléatoire d'un nombre entre 0 et 100
	const int random_int = randint(100);
	
	// On définit 2 variables
	int temp = 0; // Variable dans laquelle on stock les essaies de l'utilisateur
	int cpt = 0; // Variable dans laquelle on stock le nombre d'essaies

	printf("IA > Je pense à un nombre entre 0 et 100, tu dois le trouver.\n");

	// On fait une boucle tant que la valeur aléatoire et les essaies de l'utilisateur ne sont pas égaux
	while (temp != random_int) {
		printf("Humain > ");
		scanf("%d", &temp); // Entré de l'utilisateur

		// Condition qui verifie que l'utilisateur perd
		if (temp != random_int)
		{
			// Condition qui permet de guider l'utilisateur
			if (temp > random_int) 
			{
				printf("IA > Trop grand !\n");
			}
			else
			{
				printf("IA > Trop petit !\n");
			}

			// Incrémentation du compteur d'essaies
			cpt += 1;
		}
	}

	printf("IA > Bravo, tu as trouvé en %d coups !\n", cpt);

	return 0;
}

int randint (int max)
{
	// On définit la graine du pseudo aléatoire avec le temps
	srand(time(NULL));

	// On tire un nombre aléatoire entre 0 et max (inclu)
	return rand() % (max + 1);
}
