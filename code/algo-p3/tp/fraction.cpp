#include <iostream>

struct fraction {
	int numerateur;
	int denumumerateur;
};

void saisie (fraction &frac)
{
	int num, denum;
	
	do
	{
		std::cout << "Saisie d'une fraction (deux entiers, dont un dénominateur non-nul), \nNumérateur: ";
		std::cin >> num;
		std::cout << "Dénominateur: ";
		std::cin >> denum;

		if (denum <= 0)
		{
			std::cout << "Le dénominateur est inférieur ou égale à 0, recommencez la saisie.";
		}
		else {
			frac.numerateur = num;
			frac.denumumerateur = denum;
		}
	} while (denum <= 0);
}

void affichage (fraction frac)
{
	std::cout << frac.numerateur << "/" << frac.denumumerateur;
}

fraction multiplication (fraction frac1, fraction frac2)
{
	fraction frac;

	frac.numerateur = frac1.numerateur * frac2.numerateur;
	frac.denumumerateur = frac1.denumumerateur * frac2.denumumerateur;
	
	return frac;
}

fraction addition (fraction frac1, fraction frac2)
{
	fraction frac;

	if (frac1.denumumerateur == frac2.denumumerateur)
	{
		frac.denumumerateur = frac1.denumumerateur;
		frac.numerateur = frac1.numerateur + frac2.numerateur;
	
		return frac;
	}

	frac.numerateur = (frac1.numerateur * frac2.denumumerateur) + (frac2.numerateur * frac1.denumumerateur);
	frac.denumumerateur = frac1.denumumerateur * frac2.denumumerateur;

	return frac;
}

fraction oppose (fraction frac)
{
	fraction retour;

	retour.numerateur = -frac.numerateur;
	retour.denumumerateur = frac.denumumerateur;

	return retour;
}

fraction inverse (fraction frac)
{
	fraction retour;

	if (frac.numerateur * frac.denumumerateur == 1)
	{
		retour.numerateur = frac.denumumerateur;
		retour.denumumerateur = frac.numerateur;
		
		return retour;
	}

	return frac;
}

fraction soustraction (fraction frac1, fraction frac2)
{
	fraction frac;

	if (frac1.denumumerateur == frac2.denumumerateur)
	{
		frac.denumumerateur = frac1.denumumerateur;
		frac.numerateur = frac1.numerateur - frac2.numerateur;
	
		return frac;
	}

	frac.numerateur = (frac1.numerateur * frac2.denumumerateur) - (frac2.numerateur * frac1.denumumerateur);
	frac.denumumerateur = frac1.denumumerateur * frac2.denumumerateur;

	return frac;
}

fraction division (fraction frac1, fraction frac2)
{
	fraction frac;

	frac.numerateur = frac1.numerateur * frac2.numerateur;
	frac.denumumerateur = frac1.denumumerateur * frac2.denumumerateur;

	return frac;
}

int pgcd (int a, int b)
{
	if (a == 0)
	{
		return b;
	}

	if (b == 0)
	{
		return a;
	}

	if (a > b)
	{
		return pgcd (a - b, b);
	}

	return pgcd (a, b - a);
}

int main ()
{
	fraction frac;

	saisie(frac);

	affichage(frac);

	return 0;
}