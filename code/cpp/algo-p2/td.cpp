#include <iostream>
#include <array>
#include <math.h>

const int ageMax = 100;
using tabAge = std::array<int, ageMax>; 

void Fusion (tabAge tableau1, int tailleTab1, tabAge tableau2, int tailleTab2, tabAge &tableauFusionne, int tailleTabFusion) {
	
}

void Init (tabAge &tableau)
{
	for (int k = 0; k < ageMax; k++) 
	{
		tableau[k] = 0;
	}
}

void Saisie (tabAge &tableau) 
{
	int ageTemp;

	std::cout << "Entrez un âge, pour arrêter la saisie entrez une valeur négative :";
	
	do {
		std::cin >> ageTemp;

		if (ageTemp >= 0 && ageTemp < 100)
		{
			tableau[ageTemp]++;
		}
	}
	while (ageTemp < 0);
}

void Regroupe (tabAge tab1, tabAge tab2, tabAge &tab3)
// On suppose que le tab3 est initialisé
// On addition le tableau 1 et le tableau 2 dans le tableau 3
{
	for (int k = 0; k < ageMax; k++)
	{
		tab3[k] = tab1[k] + tab2[k];
	}	
}

float Moyenne (tabAge tableau)
{
	int numerateur = 0;
	int diviseur = 0;

	for (int k = 0; k < ageMax; k++)
	{
		numerateur += tableau[k] * k;
		diviseur += tableau[k];
	}

	if (diviseur == 0)
	{
		return 0;
	}

	return numerateur / diviseur;
}

float Variance (tabAge tableau)
{
	float moyenne = Moyenne(tableau);
	int numerateur = 0;
	int diviseur = 0;

	for (int k = 0; k < ageMax; k++)
	{
		numerateur += pow(tableau[k] - moyenne, 2);
		diviseur += tableau[k];
	}

	if (diviseur == 0)
	{
		return 0;
	}

	return numerateur / diviseur;
}

float EcartType (tabAge tableau)
{
	float variance = Variance(tableau);

	return sqrt(variance);
}

int ValeurMediane (tabAge tableau)
{	
	if (ageMax % 2 == 0)
	{
		return (tableau[ageMax / 2] + tableau[(ageMax+1) / 2]) / 2;
	}

	return tableau[floor((ageMax+1) / 2)];
}

void Affichage (tabAge tableau)
{
	for (int k = 0; k < ageMax; k++)
	{
		if (k > 0)
		{
			std::cout << k << " : " << tableau[k] << std::endl;
		}	
	}
}

int main ()
{
	tabAge tableauMain;

	Init(tableauMain);

	return 0;
}