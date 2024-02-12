#include <iostream>
#include <cstdlib>


int randint (int min, int max) 
{	
	srand((unsigned) time(NULL));	

	return min + (rand() % (max - min));
}

int array_length (int array[])
{
	int cpt;

	for (auto k: array)
	{
		cpt++;
	}

	return cpt;
}

int [] create_random_array ()
{
	int nMax = 10000;

	int array[nMax];

	for (int k = 0; k < nMax; k++)
	{
		array[k] = randint(-99999, 99999);
	}

	return array;
}

int[] quick_sort ()
{
}