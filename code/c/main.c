#include <stdio.h>

int fill_array(int array_length)
{
	int array[array_length];

	for (int k = 0; k < array_length; k++)
	{
		int temp = 0;

		printf("Entrez une valeur a stocker dans le tableau: ");
		scanf("%d", &temp);

		array[k] = temp;
	}

	printf("Le tableau est complet. \n");

	return array;
}

void display_array(int array[], int array_length)
{
	for (int k = 0; k < array_length; k++)
	{
		printf("%d\n", array[k]);
	}
}

int main (void)
{
	const int len = 10;
	int array[len] = fill_array(len);

	display_array(array, len);
}
