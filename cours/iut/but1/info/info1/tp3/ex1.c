#include <stdio.h>

// On déclare la procédure bonjour
void bonjour (void);

int main (void)
{
	// On appele la procédure bonjour 50 fois
	for (int k = 0; k < 50; k++) bonjour();

	return 0;
}

void bonjour (void)
{
	// On affiche bonjour!
	printf("Bonjour !\n");
}
