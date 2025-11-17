#include <stdio.h>
#include <time.h>

void AvanceHeure (unsigned char * heure, unsigned char * minute, unsigned char * seconde);

void Pause (int number_of_seconds);


int main (void)
{
	unsigned char heure = 0;
	unsigned char minute = 0;
	unsigned char seconde = 0;

	while (1)
	{
		printf("%02d:%02d:%02d\n", heure, minute, seconde);
		
		AvanceHeure(&heure, &minute, &seconde);
		
		Pause (1);
	}

	return 0;
}


void AvanceHeure (unsigned char * heure, unsigned char * minute, unsigned char * seconde)
{
	if (*seconde == 59)
	{
		*seconde = 0;

		if (*minute >= 60)
		{
			*minute = 0;
			
			if (*heure >= 24)
			{
				*heure = 0;
			}
			else *heure += 1;
		}
		else *minute += 1;
	}
	else *seconde += 1;

	


	
}


void Pause (int number_of_seconds)
{
	unsigned int time_t = time(0) + number_of_seconds;

	while (time(0) < time_t);
}
