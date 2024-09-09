#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t getCurrentTime (void);
time_t getDifferenceTime (time_t start, time_t stop);
int * getFormattedTime (time_t timestamp);
void displayTime (int formattedTime[3]);
void askRandomMultiplication (time_t * array, int &size);
int randint (int max);

int main (void)
{
	int times_size = 0;
	time_t times[255];

	askRandomMultiplication(times, times_size);





	// int temp = 0;

	// int startTime, stopTime;

	// startTime = getCurrentTime();

	// printf("votre chiffre preferer: ");
	// scanf("%d", &temp);

	// stopTime = getCurrentTime();

	// printf("vous avez mis ");
	// displayTime(getFormattedTime(getDifferenceTime(startTime, stopTime)));

	return 0;
}

time_t getCurrentTime (void)
{
	return time(NULL);
}

time_t getDifferenceTime (time_t start, time_t stop)
{
	return stop - start;
}

int * getFormattedTime (time_t timestamp)
{
	static int formattedTime[3];

	formattedTime[0] = timestamp / 3600;
	formattedTime[1] = (timestamp % 3600) / 60;
	formattedTime[2] = timestamp % 60;

	return formattedTime;
}

void displayTime (int formattedTime[3])
{
	if (formattedTime[0] != 0) printf("%dh", formattedTime[0]);
	if (formattedTime[1] != 0) printf("%dm", formattedTime[1]);
	
	printf("%ds\n", formattedTime[2]);
}

void askRandomMultiplication (time_t * array, int &size)
{
	time_t start = getCurrentTime();
	int a = randint(10);
	int b = randint(10);
	int temp = 0;
	
	do
	{
		printf("%d x %d = ", a, b);
		scanf("%d", &temp);

		if ()
	}
	while ((a*b) == temp);

	time_t stop = getCurrentTime();
}

int randint (int max)
{
	// On définit la graine du pseudo aléatoire avec le temps
	srand(time(NULL));

	// On tire un nombre aléatoire entre 0 et max (inclu)
	return rand() % (max + 1);
}
