#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double getDifferenceTime (clock_t start, clock_t stop);
double calculateAverage (double * array, int size);
void askRandomMultiplication (double * array, int * size);
int randint (int max);

int main (void)
{	
	int times_size = 0;
	int cpt = 0;
	double times[255];
	double average = 0;

	// On définit la graine du pseudo aléatoire avec le temps
	srand(time(NULL));

	while (cpt == times_size)
	{
		askRandomMultiplication(times, &times_size);
	
		cpt++;
	}

	average = calculateAverage(times, times_size);

	printf("==> Temps moyen de réponse : %.0fms", average);
	
	return 0;
}

double getDifferenceTime (clock_t start, clock_t stop)
{
	return (stop - start) / CLOCKSPER;
}

double calculateAverage (double * array, int size)
{
	double average = 0;

	for (int k = 0; k < size; k++)
	{
		average = average + array[k];
	}

	return average / size; 
}

void askRandomMultiplication (double * array, int * size)
{
	struct timeval tval_before, tval_after, tval_result;

	// clock_t start, stop;

	double diff = 0;

	int a = randint(10);
	int b = randint(10);
	int temp = 0;
	
	gettimeofday(&tval_before, NULL);

	do
	{
		printf("%d x %d = ", a, b);
		scanf("%d", &temp);
	}
	while ((a*b) != temp && temp != -1);

	gettimeofday(&tval_after, NULL);

	if (temp != -1)
	{
		timersub();

		printf("Vous avez trouvé en %fms\n", diff);

		array[*size] = diff;

		(*size)++;
	}
}

int randint (int max)
{
	// On tire un nombre aléatoire entre 0 et max (inclu)
	return rand() % (max + 1);
}
