#include <iostream>
#include <string>
#include <array>

struct lecteur
{
	int id;
	std::string nom;
	std::string prenom;
};

struct enslecteurs 
{
	int nbLecteurs;
	std::array <lecteur, nbLecteurs> lecteurs;
};

void saisie (lecteur &lect)
{
	std::cout << "Saisie d'un lecteur: \nIdentifiant: ";
	std::cin >> lect.id;

	std::cout << "Nom: ";
	std::cin >> lect.nom;

	std::cout << "Prénom: ";
	std::cin >> lect.prenom;
}

void affichage (lecteur lect)
{
	std::cout << "Lecteur n°" << lect.id << ": \n";
	std::cout << "Nom: " << lect.nom << "\n";
	std::cout << "Prénom: " << lect.prenom << "\n";
}


int main ()
{
	lecteur toto;

	saisie(toto);

	affichage (toto);

	return 0;
}