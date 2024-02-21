#include <iostream>
#include <array>

const int nMax = 999;

using Jeu = std::array<char, nMax>;

void Init (Jeu &plateau, int nbMoutons, int &taillePlateau)
{
    taillePlateau = 2*nbMoutons + 1;

    // On insere M moutons blanc
    for (int k = 0; k < nbMoutons; k++)
    {
        plateau[k] = 'B';
    }
    
    // On insere un emplacement vide
    plateau[nbMoutons] = 'X';

    // On insere M moutons noir
    for (int k = nbMoutons + 1; k < taillePlateau; k++)
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

bool Gagne (Jeu plateau, int taillePlateau)
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

bool CaseVide (Jeu plateau, int indiceCase)
{
    if (plateau[indiceCase] == 'X')
    {
        return true;
    }

    return false;
}

bool EstJouable(Jeu plateau, int indiceCaseDep, int indiceCaseArr)
{
    if (!CaseVide(plateau, indiceCaseArr))
    {
        return false;
    }

    if (abs(indiceCaseDep - indiceCaseArr) != 2)
    {
        return false;
    }

    return true;
}


void Echange (Jeu &plateau, int posCaseDep, int posCaseArr)
{
    char temp = plateau[posCaseDep];

    plateau[posCaseDep] = plateau[posCaseArr];
    plateau[posCaseArr] = plateau[temp];
}

char DemandeChoix ()
{
    char choix;

    std::cout << "Choissisez un mouton a deplacer (B/N): ";
    std::cin >> choix; // soit B ou N

    if (choix == 'B' || choix == 'N' || choix == 'b' || choix == 'n')
    {
        return choix;
    }

    return -1;
}

bool Deplacement (Jeu &plateau, int taillePlateau, char caseADep, int distance)
{
    for (int k = 0; k < taillePlateau - 1; k++)
    {
        if (plateau[k] == caseADep && plateau[k + (distance)] == 'X')
        {
            if (!EstJouable(plateau, k, k + (distance)))
            {
                return false;
            }
            
            Echange(plateau, k, k + (distance));
            
            return true;
        }
    }

    return false;
}

void Joue (Jeu &plateau, int taillePlateau)
{
    do
    {
        char choix = DemandeChoix();
        bool estDeplacer;
        
        if (choix 
        {
            if (choix == 'B' || choix == 'b')
            {
                Deplacement(plateau, taillePlateau, 'B'; 2);   
            }
            else if (choix == 'N' || choix == 'n')
            {
                Deplacement(plateau, taillePlateau, 'N', -2);   
            }
        }
    } 
    while (Gagne(plateau, taillePlateau));
}



int main ()
{  
    int nbMoutons = -1;
    int taillePlateau;
    Jeu plateau;

    std::cout << "Le jeu du saute-moutons se joue avec M moutons noirs et M moutons blancs positionnés en ligne. On les représente dans un tableau. Le caractère B représente un mouton blanc, N un mouton noir. \n Le but du jeu est d’inverser les positions des moutons blancs et noirs, sachant que : \n • les moutons blancs ne peuvent avancer que vers la droite \n • les moutons noirs ne peuvent avancer que vers la gauche \n • un mouton peut avancer si la case suivante est libre (exemple 2 vers 3, ou 4 vers 3)  \n • un mouton peut sauter si la case suivante est un autre mouton et celle d’après est libre (exemple 1 vers 3 ou 5 vers 3)  \n • si plus aucun mouton ne peut bouger, la partie est perdue  \n • si les moutons ont inversé leur position, la partie est gagnée. \n\n\n Entrez maintenant un nombre de mouton pour le jeu: ";

    std::cin >> nbMoutons;

    if (nbMoutons >= 0)
    {
        std::cout << "Le nombre de moutons doit etre superieur a 0.";

        return 0;
    }

    Init(plateau, nbMoutons, taillePlateau);

    std::cout << "Voici le plateau de jeu: \n";

    Affichage(plateau, taillePlateau);

    std::cout << "\nMaintenant, jouons :\n";

    Joue(plateau, taillePlateau);

    return 0;
}