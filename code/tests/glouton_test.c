#include <stdio.h>
#include <assert.h>


typedef struct rendu
{
	int monnaie;
	int nombre;
} rendu;


rendu * rendu_monnaie(int montant, int * systeme);


int main (void)
{
	const int systeme_monnaie[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

	return 0;
}


rendu * rendu_monnaie(int montant, int * systeme)
{
	
}
