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

using repertoire = maillon *;

void supprimerPremier (repertoire & R)
{
	repertoire aux = R;

	R = R->suiv;

	delete aux;
}

void vide (repertoire & R)
{
	if (R != nullptr)
	{
		supprimerPremier(R);

		vide(R);
	}
}

void initialiserRepertoire (repertoire & R)
{
	if (R != nullptr) vide(R);

	R = nullptr;
}

void ajouterEnTete (std::string nom, std::string prenom, std::string tel, repertoire & R)
{
	repertoire aux = R;
	personne temp;

	temp.nom = nom;
	temp.prenom = prenom;
	temp.tel = tel;

	R->val = temp;
	R->suiv = aux;
}

void ajouterEnQueue (std::string nom, std::string prenom, std::string tel, repertoire & R)
{
	if (R != nullptr && R->suiv != nullptr)
	{
		return ajouterEnQueue(nom, prenom, tel, R);
	}

	repertoire aux;
	personne temp;

	temp.nom = nom;
	temp.prenom = prenom;
	temp.tel = tel;

	aux->val = temp;
	aux->suiv = nullptr;

	R->suiv = aux;
}

void afficherPersonne (personne P)
{
	
}

int main (void)
{
	return 0;
}