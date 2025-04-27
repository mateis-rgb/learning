#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10000

float moyenne (float * notes, size_t taille);

int main (void)
{	
	float notes[SIZE];

	srand(time(NULL));

	for (int k = 0; k < SIZE; k++)
	{
		notes[k] = 0 + (float)rand() / ((float)RAND_MAX/(20-0));
	}

	printf("Moyenne = %f\n", moyenne(notes, SIZE));

	return 0;
}

float moyenne (float * notes, size_t taille)
{
	size_t k = 0;
	float moyenne = 0;

	for (k = 0; k < taille; k++) moyenne += notes[k];

	return moyenne / taille;
}
