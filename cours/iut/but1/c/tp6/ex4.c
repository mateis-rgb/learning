#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initRandom (int array[], int size);

int min (int array[], int size);

int max (int array[], int size);


int main (void)
{
	int tab[SIZE];

	srand(time(NULL));

	initRandom(tab, SIZE);

	printf("min = %d\n", min(tab, SIZE));
	printf("max = %d\n", max(tab, SIZE));

	return 0;
}

void initRandom (int array[], int size)
{
	for (int i = 0; i < size; i++) array[i] = rand() % 100 + 1;
}

int min (int array[], int size)
{
	int mini = array[0];
	int k = 0;

	for (k = 1; k < size; k++)
	{
		if (array[k] < mini) mini = array[k];
	}

	return mini;
}

int max (int array[], int size)
{
	int maxi = array[0];
	int k = 0;

	for (k = 1; k < size; k++)
	{
		if (array[k] > maxi) maxi = array[k];
	}

	return maxi;
}
