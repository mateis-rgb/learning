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

// Fct qui permet de savoir si c'est gagné (trois 'x' ou 'o' alignés en ligne ou collone)
bool aGagne (matrice plateau, bool joueur_est_rond)
{
	bool resultat = false;
	char caractere_a_comparer = joueur_est_rond ? 'o' : 'x';


	// verification en colone
	for (int k = 0; k < taille_matrice; k++)
	{
		if ((plateau[0][k] == caractere_a_comparer) && (plateau[1][k] == caractere_a_comparer && plateau[2][k] == caractere_a_comparer))
		{
			resultat = true;
		}
	}

	// verification en ligne
	for (int k = 0; k < taille_matrice; k++)
	{
		if ((plateau[k][0] == caractere_a_comparer) && plateau[k][1] == caractere_a_comparer && (plateau[k][2] == caractere_a_comparer))
		{
			resultat = true;
		}
	}

	return resultat;
}

// Fct qui permet de savoir si le plateau ne peux plus etre jouer (toutes les cases sont utilisés)
bool estJouable (matrice plateau)
{
	bool resultat = false;

	for (int k = 0; k < taille_matrice; k++)
	{
		for (int i = 0; i < taille_matrice; i++)
		{
			if (estVide(plateau, k, i))
			{
				resultat = true;
			}
		}
	}

	return resultat;
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

	std::cout << "Voici le jeu du morpion, voici la grille vide: \n";
	
	affichage(plateau);

	do
	{
		for (int k = 0; k <= 1; k++)
		{
			int x, y;

			do {
				std::cout << "\nJoueur "<< k + 1 <<" a votre tour, entrez les coordonnées (x, y) où vous jouez:";
				std::cin >> x >> y;
			}
			while (!estVide(plateau, x, y));

			jouer(plateau, x, y, k);

			affichage(plateau);

			if (k == 0)
			{
				if (aGagne(plateau, k))
				{
					std::cout << "\nBravo, vous avez gagné.\n";

					return 0;
				}
			}
			else
			{
				if (aGagne(plateau, k))
				{
					std::cout << "\nBravo, vous avez gagné.\n";

					return 0;
				}
			}
		}

		nbCoups++;
	}
	while (estJouable(plateau));

	return 0;
}