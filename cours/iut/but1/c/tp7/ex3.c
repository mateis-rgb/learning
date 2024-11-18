#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randint (int min, int max);


char * ExcuseOTron (const char * sujet, const char * verbe, const char * complement);


int main (void)
{
	srand(time(NULL));

	const char sujet[4][50]={
		"une prof de culture-com ",
		"un extraterrestre ",
		"un loubard ",
		"un chauffeur de bus "
	};

	const char verbe[4][50]={
		"m'a retenu ",
		"m'a kidnappe ",
		"m'a choppé ",
		"m'a oublié "
	};

	const char complement[4][50]={
		"à la fin du cours.",
		"dans son vaisseau spatial.",
		"dans un coin sombre.",
		"dans son depot."
	};

	printf("%s\n", ExcuseOTron(sujet[randint(0, 3)], verbe[randint(0, 3)], complement[randint(0, 3)]));

	return 0;
}


int randint (int min, int max)
{
	return min + rand() % (max + 1 - min);
}


char * ExcuseOTron (const char * sujet, const char * verbe, const char * complement)
{
	char * excuse = malloc(200*sizeof(char));

	strcat(excuse, "Je suis en retard parce qu'");
	strcat(excuse, sujet);
	strcat(excuse, verbe);
	strcat(excuse, complement);

	return excuse;
}
