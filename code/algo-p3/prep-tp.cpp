#include <iostream>
#include <string>
#include <fstream>

struct film {
	std::string titre;
	int annee;
	std::string realisateur;
	int duree;
	std::string langue;
};

struct ensemble {
	film *films;
	int nbFilms;
};

// struct selection {
// 	film *films[];
// };

void import (ensemble &ens, std::string path)
{
	std::ifstream file;
	file.open(path);

	if (!file.is_open())
	{
		std::cout << "L'ouverture du fichier a échouée.\n";
	
		return;
	}

	std::string ligne;
	std::getline(file, ligne);
	
	ens.nbFilms = std::stoi(ligne);

	int compteur = 0;
	int current_film = 0;

	while(file.good())
	{
		film film_temp;

		switch (compteur)
		{
			case 0:
				// tire
				film_temp.titre = ligne;
				break;
			
			case 1:
				// année
				film_temp.annee = ligne;
				break;
			
			case 2:
				// realisateur
				film_temp.realisateur = ligne;
				break;

			case 3:
				// durée
				film_temp.duree = ligne;
				break;

			case 4:
				// langue
				film_temp.langue = ligne;
				break;
		}

		std::getline(file, ligne);

		if (compteur == 4)
		{
			ens.films[current_film] = film_temp;

			compteur = 0;
		}
	}
}

int main (void)
{
	ensemble ens;

	import(ens, "./toto.txt");
}