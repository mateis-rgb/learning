#include <stdio.h>

struct frct {
	int numerateur;
	int denominateur;
};

typedef struct frct Fraction;

void saisie (Fraction &frac)
{
	scanf("%d", frac->numerateur);

	printf("\n%d\n", frac->numerateur);	
}

int main ()
{
	Fraction frac;

	// frac.numerateur = 5;
	// frac.denominateur = 5;

	// printf("numérateur: %d\n", frac.numerateur);
	// printf("dénominateur: %d\n", frac.denominateur);

	saisie(frac);

	return 0;
}