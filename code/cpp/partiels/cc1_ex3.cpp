#include <iostream>
#include <array>
#include <string>

int main ()
{
    const int nbVoyellesMax = 6;
    const int nbAdnMax = 4;
    int nbVoyellesDansMot = 0;
    bool estADN = true;
    std::string chaine, chaine2;
    std::array<char, nbVoyellesMax> voyelles = {'a', 'e', 'i', 'o', 'u', 'y'};
    std::array<int, nbVoyellesMax> voyellesDansMot = {0, 0, 0, 0, 0, 0};
    std::array<char, nbAdnMax> ADN = {'a', 'c', 't', 'g'};


    std::cout << "Saisir une chaine : ";
    std::cin >> chaine;

    for (int k = 0; k < chaine.length(); k++)
    {
        for (int i = 0; i < nbVoyellesMax; i++)
        {
            if (chaine[k] == voyelles[i])
            {
                nbVoyellesDansMot++;
                voyellesDansMot[i]++;
            }
        }
    }

    std::cout << "Il y a " << nbVoyellesDansMot << " voyelles." << std::endl;
    std::cout << "Chaine de voyelles : ";

    for (int k = 0; k < nbVoyellesMax; k++)
    {
        if (voyellesDansMot[k] != 0)
        {
            for (int i = 0; i < voyellesDansMot[k]; i++)
            {
                std::cout << voyelles[k];
            }
        }
    }

    std::cout << std::endl;

    std::cout << "Saisir une autre chaine : ";
    std::cin >> chaine2;

    if (chaine.length() != chaine2.length())
    {
        std::cout << "Les chaines sont de longueurs différentes." << std::endl;
    }

    // On admet la suite de la question


    for (int k = 0; k < chaine.length(); k++)
    {
        for (int i = 0; i < nbAdnMax; i++)
        {
            if (chaine[k] != ADN[i])
            {
                estADN = false;
            }
        }
    }

    if (estADN == true)
    {
        std::cout << chaine << " est une séquence ADN." << std::endl;
    }

    return 0;
}