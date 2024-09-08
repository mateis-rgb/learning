#include <stdio.h>
#include <time.h>

time_t getCurrentTime (void);
time_t getDifferenceTime (time_t start, time_t stop);
int * getFormattedTime (time_t timestamp);
void displayTime (int formattedTime[3]);

int main (void)
{
	int temp = 0;

	int startTime, stopTime;

	startTime = getCurrentTime();

	printf("votre chiffre preferer: ");
	scanf("%d", &temp);

	stopTime = getCurrentTime();

	printf("vous avez mis ");
	displayTime(getFormattedTime(getDifferenceTime(startTime, stopTime)));

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

void displayTime (int formattedTime[4])
{
	if (formattedTime[0] != 0) printf("%dh", formattedTime[0]);
	if (formattedTime[1] != 0) printf("%dm", formattedTime[1]);
	
	printf("%ds\n", formattedTime[2]);
}
