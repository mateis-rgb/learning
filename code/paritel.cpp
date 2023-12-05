#include <iostream>
#include <array>

const int nMax = 99;

using lignes = std::array<char, nMax>;
using matrice = std::array<lignes, nMax>;

// Procédure d'initialisation
void init (matrice &plateau, int &lignes, int &colones)
{
	// Demande à l'utilisateur un nb de lignes et un nb de colone pour le plateau de jeu, on ne s'occupera pas de la vérification des données. Je suppose que l'utilisateur entre deux entiers positifs
	std::cout << "Sur quelle taille de grille voulez-vous jouer (nombre de lignes puis nombre de colonnes, deux entiers positifs) ? ";
	std::cin >> lignes >> colones;

	// On remplit le tableau avec des caractères espace ' '
	for (int k = 0; k < lignes; k++)
	{
		for (int i = 0; i < colones; i++)
		{
			plateau[k][i] = ' ';
		}
	}
}

// Procédure d'affichage.
void affichage (matrice plateau, int lignes, int colones)
{
	for (int k = 0; k <= lignes; k++)
	{		
		for (int i = 0; i < colones; i++)
		{
			if (k == lignes)
			{
				std::cout << " " << i + 1 << "  ";
			}
			else
			{
				if (i == 0)
				{
					std::cout << "| ";
				}

				std::cout << plateau[k][i] << " | ";
			}
		}

		std::cout << "\n";
	}
}

// La fonction coloneJouable regarde si une est jouable ou non.
bool coloneJouable (matrice plateau, int lignes, int colones)
{
	int k = 0;
	bool colone_non_trouve = true;
	
	// On parcours les premiers éléments (les éléments en haut du plateau de jeu) pour voir si une colone est complète ou non
	while (k < colones && colone_non_trouve)
	{
		if (plateau[0][k] == ' ')
		{
			colone_non_trouve = false;
		}
	}

	// On retourne l'inverse d'une colone_non_trouve puisqu'on a trouver une colone vide
	return !colone_non_trouve;
}

// Cette procédure met dans le plateau a l'indice le plus bas le caractère associé au joueur 
void deplacement (matrice &plateau, int lignes, int colone_choisis, char joueur)
{
	int k = lignes - 1;
	bool emplacement_non_trouve = true;

	// On parcours toutes les lignes (dans le sens inverse) de la colone choisis et lorsque l'on trouve un caractère ' ' on place a cet indice le caractère du joueur.
	while (k >= 0 && emplacement_non_trouve)
	{
		if (plateau[k][colone_choisis] == ' ')
		{
			plateau[k][colone_choisis] = joueur;
			emplacement_non_trouve = false;
		}

		k--;
	}
}

// La procédure joue permet de jouer à l'utilisateur (modélisé par le charactère joueur (O ou X)). Elle prend en paramètre le plateau de jeu, un nb de lignes et de colones.
void joue (matrice &plateau, int lignes, int colones, char &joueur)
{
	int colone_temp;
	bool valid = true;

	// On boucle tant que le déplacement n'est pas fait
	do
	{
		// Je suppose que l'utilisateur rentre un numéro de colone qui fait parti du nombre maximale de colone dans le plateau de jeu
		std::cout << "Joueur "<< joueur <<", dans quelle colone voulez-vous jouer ? ";
		std::cin >> colone_temp;

		// L'affichage de l'utilisateur n'est pas sous forme d'indice, il faut donc retirer 1 a l'entrée de l'utilisateur.
		colone_temp--;

		if (plateau[0][colone_temp] == ' ')
		{
			deplacement(plateau, lignes, colone_temp, joueur);
			
			valid = false;
		}
		else
		{
			std::cout << "La colone est complète. \n";
		}
	}
	while (valid);

	// On fait le changement du joueur a l'aide d'un ternaire.
	joueur = joueur == 'O' ? 'X' : 'O';
}

// La fonction alignementEnLigne regarde s'il y a un alignement en lignes de 4 caractère du joueur. Elle prend en paramètre le plateau de jeu, le nb de lignes et de colones, la ligne à tester et le caractère associé au joueur.
bool alignemengEnLigne (matrice plateau, int lignes, int colones, int ligne_choisis, char joueur)
{
	int k = 0;
	// compteur de l'alignement (s'il est égale à 4 la fonction retourne vrai sinon faux)
	int cpt = 0; 
	bool alignement_non_trouve = true;

	while (k < colones && alignement_non_trouve)
	{
		// Si le caractère de la case est égale au joueur on incrément de 1 le compteur
		if (plateau[ligne_choisis][k] == joueur)
		{
			cpt++;

			// Si le compteur est égale à 4 on arrète la boucle
			if (cpt == 4)
			{
				alignement_non_trouve = false;
			}
			// Sinon si le compteur de la boucle + 1 n'est pas égale aux nombres de colones
			else if ((k+1) != colones)
			{
				// Si le caractère de la case n'est pas égale au joueur on met le compteur à 0;
				if (plateau[ligne_choisis][k+1] != joueur)
				{
					cpt = 0;
				}
			}
		}

		k++;
	}

	// Retourne vrai si le compteur est égal à 4 sinon faux.
	return cpt == 4;
}

// La fonction alignementEnColone regarde s'il y a un alignement en colone de 4 caractère du joueur. Elle prend en paramètre le plateau de jeu, le nb de lignes et de colones, la colone à tester et le caractère associé au joueur.
bool alignemengEnColone (matrice plateau, int lignes, int colones, int colone_choisis, char joueur)
{
	int k = 0;
	// compteur de l'alignement (s'il est égale à 4 la fonction retourne vrai sinon faux)
	int cpt = 0; 
	bool alignement_non_trouve = true;

	while (k < lignes && alignement_non_trouve)
	{
		// Si le caractère de la case est égale au joueur on incrément de 1 le compteur
		if (plateau[k][colone_choisis] == joueur)
		{
			cpt++;

			// Si le compteur est égale à 4 on arrète la boucle
			if (cpt == 4)
			{
				alignement_non_trouve = false;
			}
			// Sinon si le compteur de la boucle + 1 n'est pas égale aux nombres de colones
			else if ((k+1) != lignes)
			{
				// Si le caractère de la case n'est pas égale au joueur on met le compteur à 0;
				if (plateau[k+1][colone_choisis] != joueur)
				{
					cpt = 0;
				}
			}
		}

		k++;
	}

	// Retourne vrai si le compteur est égal à 4 sinon faux.
	return cpt == 4;
}

int main ()
{
	matrice plateau;
	int lignes, colones;
	char current_joueur = 'O';

	init(plateau, lignes, colones);

	deplacement(plateau, lignes, 2, 'X');
	deplacement(plateau, lignes, 2, 'X');
	deplacement(plateau, lignes, 2, 'O');
	deplacement(plateau, lignes, 2, 'X');
	deplacement(plateau, lignes, 2, 'X');

	affichage(plateau, lignes, colones);

	// joue(plateau, lignes, colones, current_joueur);
	// affichage(plateau, lignes, colones);

	std::cout << alignemengEnColone(plateau, lignes, colones, 2, 'X');

	// J'ai été préssé par le temps, je n'ai pas pu donc finir le programe dans son entièreté. Bonne lecture.

	return 0;
}