#include <iostream>
#include <array>

const int courreursMax = 9999;

using Dossard = std::array<int, courreursMax>;
using Temps = std::array<float, courreursMax>;

bool EstPresent (Dossard tab, int indiceMax, int numero)
{
    bool retour = false;

    for (int k = 0, k < indiceMax; k++)
    {
        if (tab[k] == numero)
        {
            retour = true;
        }
    }

    return retour;
}

void Saisie (Dossard &tabDossard, Temps &tabTemps, int &indiceMax, int &indiceMax)
{
    int dossardTemp = 0, tempsTemp = 0;

    std::cout << "Saisir un n° de dossard (entier > 0) et un temps (nb flotant > 0) \n";

    do
    {
        std::cout << "N° Dossard: ";
        std::cin >> dossardTemp;

        if (dossardTemp > 0)
        {
            if (!EstPresent(tabDossard, indiceMaxDossard, dossardTemp))
            {
                std::cout << "Temps du dossard "<< dossardTemp <<": ";
                std::cin >> tempsTemp;

                if (tempsTemp > 0)
                {
                    tabDossard[indiceMax] = dossardTemp;
                    tabTemps[indiceMax] = tempsTemp;

                    indiceMax++;
                }
            }
            else
            {
                std::cout << "Le n° de dossard est déjà présent.";
            }
        }
        else
        {
            std::cout << "Le n° de dossard doit est strictement supérieur à 0.";
        }
    } while (dossardTemp > 0 && tempsTemp > 0);   
}

void Affichage (Dossard tabDossard, Temps tabTemps, int indiceMax)
{
    for (int k = 0; k < indiceMax; k++)
    {
        std::cout << "Dossard " << tabDossard[k] << " : " << tabTemps[k] << "\n";
    }
}

int IndiceMin (Temps tabTemps, int indiceMax)
{
    int min = 0;

    for (int k = 1; k < indiceMax; k++)
    {
        if (tabTemps[min] == tabTemps[k])
        {
            if (min > k)
            {
                min = k;
            }
        }

        if (tabTemps[min] > tabTemps[k])
        {
            min = k;
        }
    }

    return min;
}

void Suppression (Temps &tabTemps, Dossard &tabDossard, int indiceCoureur, int &indiceMax)
{
    
}