#include <string>

struct film {
	std::string titre;
	int annee;
	std::string realisateur;
	int duree;
	std::string langue;
	std::string infos;
};

struct ensemble {
	int nbFilms;
	film* tableau;
};

int main ()
{
		
}