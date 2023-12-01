#include <iostream>
#include <array>

const int taille_matrice = 3;

using ligne = std::array<char, taille_matrice>;
using matrice = std::array<ligne, taille_matrice>;

// Fct qui creer le plateau
matrice init()
{
	matrice plateau;

	for (int k = 0; k < taille_matrice; k++)
	{
		for (int i = 0; i < taille_matrice; i++)
		{
			plateau[k][i] = ' ';
		}
	}

	return plateau;
}

// Fct verif si case est vide
bool estVide(matrice plateau, int x, int y)
{
	return (plateau[x][y] == ' ');
}


// Fct ecrire qui met O et X dans la matrice
// [['o', ' ', 'o'],
// ['o', 'x', ' '],
// [' ', 'x', 'x']]
void jouer (matrice &plateau, int x, int y, bool joueur_est_rond)
{
	if (estVide(plateau, x, y))
	{
		if (joueur_est_rond)
		{
			plateau[x][y] = 'o';
		}
		else
		{
			plateau[x][y] = 'x';
		}
	}
}

bool verification_colone (matrice plateau, char caractere_a_comparer)
{
	int k = 0;
	bool resultat = false;

	while (resultat || k < taille_matrice)
	{
		resultat = true;
		
		for (int i = 0; i < taille_matrice; i++)
		{
			if (plateau[i][k] != caractere_a_comparer)
			{
				resultat = false;
			}
		}

		k++;
	}
	
	return resultat;
}

bool verification_ligne (matrice plateau, char caractere_a_comparer)
{
	int k = 0;
	bool resultat = true;

	while (resultat || k < taille_matrice)
	{
		resultat = true;
		
		for (int i = 0; i < taille_matrice; i++)
		{
			if (plateau[k][i] != caractere_a_comparer)
			{
				resultat = false;
			}	
		}

		k++;
	}

	return resultat;
}

bool verification_diagonale (matrice plateau, char caractere_a_comparer)
{
	bool resultat = true;

	int indice_dernier_caractere = taille_matrice - 1;
	int k = 0;

	if (taille_matrice%2 == 0)
	{
		return false;
	}

	while (resultat || k < taille_matrice)
	{
		if (plateau[k][k] != caractere_a_comparer)
		{
			resultat = false;
		}

		k++;
	}

	if (resultat)
	{
		return resultat;
	}

	k = 0;

	while (resultat || k < taille_matrice)
	{
		if (plateau[indice_dernier_caractere - k][k] != caractere_a_comparer)
		{
			resultat = false;
		}
		
		k++;
	}

	if (resultat)
	{
		return resultat;
	}

	return resultat;
}

// Fct qui permet de savoir si c'est gagné (trois 'x' ou 'o' alignés en ligne ou collone)
bool aGagne (matrice plateau, bool joueur_est_rond)
{
	char caractere_a_comparer = joueur_est_rond ? 'o' : 'x';

	// verification en colone
	return verification_colone(plateau, caractere_a_comparer);

	// verification en ligne
	return verification_ligne(plateau, caractere_a_comparer);

	// vérification en diagonale
	return verification_diagonale(plateau, caractere_a_comparer);
}

// Fct qui permet de savoir si le plateau ne peux plus etre jouer (toutes les cases sont utilisés)
bool estJouable (matrice plateau)
{
	for (int k = 0; k < taille_matrice; k++)
	{
		for (int i = 0; i < taille_matrice; i++)
		{
			if (estVide(plateau, k, i))
			{
				return true;
			}
		}
	}

	return false;
}

// Proc affichage du plateau
// +---+---+---+
// |   |   |   |
// +---+---+---+
// |   |   |   |
// +---+---+---+
// |   |   |   |
// +---+---+---+
void affichage (matrice plateau)
{
	std::cout << "\n+---+---+---+\n";

	for (int k = 0; k < taille_matrice; k++)
	{
		std::cout << "| ";

		for (int i = 0; i < taille_matrice; i++)
		{
			std::cout << plateau[k][i] << " | ";
		}

		std::cout << "\n";
		std::cout << "+---+---+---+\n";
	}
}

int main ()
{
	matrice plateau = init();
	int nbCoups = 0;
	int joueur = -1;

	std::cout << "Voici le jeu du morpion, voici la grille vide: \n";
	
	affichage(plateau);

	do
	{
		joueur = joueur == 0 ? 1 : 0;

		int x, y;

		do {
			std::cout << "\nJoueur "<< joueur + 1 <<" a votre tour, entrez les coordonnées (x, y) où vous jouez:";
			std::cin >> x >> y;
		}
		while (!estVide(plateau, x, y));

		jouer(plateau, x, y, joueur);

		affichage(plateau);

		nbCoups++;
	}
	while (estJouable(plateau) || aGagne(plateau, joueur));

	if (!estJouable(plateau))
	{
		std::cout << "Le plateau est bloqué.\n";
	}

	if (aGagne(plateau, joueur))
	{
		std::cout << "Bravo joueur " << joueur + 1 << ", vous avez gagné.\n";
	}

	return 0;
}