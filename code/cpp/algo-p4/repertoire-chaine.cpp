#include <stdio.h>
#include <string>

struct personne
{
	std::string nom;
	std::string prenom;
	std::string tel;
};

struct maillon
{
	personne val;
	maillon * suiv;
};

using reperoire = maillon *;


void supprimer_premier (reperoire & R)
{
	reperoire aux = R;

	R = R->suiv;

	delete aux;
}


void vide (reperoire & R)
{
	if (R != nullptr)
	{
		supprimer_premier(R);

		vide(R);
	}

	R = nullptr;
}


void initialiserRepertoire (reperoire & R)
{
	if (R != nullptr) effacer (R);
}

int main (void)
{
	return 0;
}