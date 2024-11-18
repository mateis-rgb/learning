#include <stdio.h>
#include <stdlib.h>

typedef struct Harmonique
{
	int note;
	float duree;

	struct Harmonique * p;
} Harmonique;


Harmonique initHarmonique (void);

/**
 * @brief Allow user to enter his partition
 * 
 * @return Partition* 
 */
Harmonique * saisiePartition (void);

/**
 * @brief Display a partition
 * 
 * @param partition 
 */
void affichagePartition (Harmonique * partition);


int main (void)
{
	Harmonique * partition = saisiePartition();

	affichagePartition(partition);

	return 0;
}


Harmonique initHarmonique (void)
{
	Harmonique temp;

	temp.p = NULL;

	return temp;
}


Harmonique * saisiePartition (void)
{
	int noteTemp = 0;
	float dureeTemp = 0;

	Harmonique * partition = malloc(sizeof (Harmonique));
	Harmonique temp = initHarmonique();

	printf("Entrez la partition d'un morceau avec ces notes et leurs durees correspondantes:\n");
	printf("(Entrez un nombre negatif pour arreter la saisie) \n");

	do
	{
		printf("Note (en Hz): ");
		scanf("%d", &noteTemp);

		if (noteTemp > 0)
		{
			printf("Duree de la note (en sec): ");
			scanf("%f", &dureeTemp);

			temp.note = noteTemp;
			temp.duree = dureeTemp;

			partition->p = &temp;
		}
	}
	while (noteTemp > 0);

	return partition;
}


void affichagePartition (Harmonique * partition)
{
	if (partition->p != NULL)
	{
		printf("%d(%.2f) ", partition->p->note, partition->p->duree);

		return affichagePartition(partition->p->p);
	} 

	printf("\n");
}


