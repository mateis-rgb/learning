#include <iostream>
#include <cstdlib>

const int nMax = 10000;

int randint (int min, int max) 
{	
	srand((unsigned) time(NULL));	

	return min + (rand() % (max - min));
}

int array_length (int array[])
{
	return *(&array + 1) - array;
}

int* create_random_array ()
{
	static int arr[nMax];

	for (int k = 0; k < nMax; k++)
	{
		arr[k] = randint(-99999, 99999);
	}

	return arr;
}

int* quick_sort (int arr[])
{
	if (array_length(arr) < 2)
	{
		return arr;
	}

	int pivot_index = array_length(arr) - 1;
	int pivot = arr[pivot_index];

	const int l_length = array_length(arr) - 1 / 2;
	const int g_length = array_length(arr) - l_length;

	static int lesser[l_length], greater[g_length];

	int l_index = 0; 
	int g_index = 0;

	for (int k = 0; k < pivot_index; k++)
	{
		if (arr[k] <= pivot)
		{
			lesser[l_index] = arr[k];

			l_index++;
		}

		if (arr[k] > pivot)
		{
			greater[g_index] = arr[k];

			g_index++;
		}
	}

	return quick_sort(lesser) + pivot + quick_sort(greater);
}

int main ()
{
	return 0;
}