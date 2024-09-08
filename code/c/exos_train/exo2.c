#include <stdio.h>
#include <time.h>

time_t getCurrentTime ();
time_t getDifferenceTime (time_t start, time_t stop);

int main (void)
{
	int temp = 0;

	int startTime, stopTime;

	startTime = getCurrentTime();

	printf("votre chiffre preferer: ");
	scanf("%d", &temp);

	stopTime = getCurrentTime();

	printf("votre temps de reflexion est estime a : %ld", getDifferenceTime(startTime, stopTime));

	return 0;
}

time_t getCurrentTime ()
{
	return time(NULL);
}

time_t getDifferenceTime (time_t start, time_t stop)
{
	return stop - start;
}