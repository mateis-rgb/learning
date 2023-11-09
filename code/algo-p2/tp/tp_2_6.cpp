#include <iostream>
#include <array>

const int nMax = 999;

using Jeu = std::array<char, nMax>;

void Init (Jeu &plateau, int nbMoutons)
{
    // On insere M moutons blanc
    for (int k = 0; k < nbMoutons; k++)
    {
        plateau[k] = 'B';
    }
    
    // On insere un emplacement vide
    plateau[nbMoutons] = 'X';

    // On insere M moutons noir
    for (int k = nbMoutons + 1; k < (2 * nbMoutons + 1); k++)
    {
        plateau[k] = 'N';
    }
}

void Affichage (Jeu plateau, int taillePlateau)
{
    std::cout << " | ";
    
    for (int k = 0; k < taillePlateau; k++)
    {
        if (plateau[k] == 'X') {
            std::cout << "  | ";
        }
        else {
            std::cout << plateau[k] << " | ";
        }
    }

    std::cout << std::endl;
}

bool gagne (Jeu plateau, int taillePlateau)
{
    Jeu plateauGagnant;
    int taille = (taillePlateau - 1) / 2;

    for (int k = 0; k < taille; k++)
    {
        plateauGagnant[k] = 'N';
    }
    
    plateauGagnant[taille] = 'X';

    for (int k = taille + 1; k < taillePlateau; k++)
    {
        plateauGagnant[k] = 'B';
    }

    if (plateau == plateauGagnant)
    {
        return true;
    }

    return false;
}



int main ()
{


    return 0;
}