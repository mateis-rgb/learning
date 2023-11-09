#include <iostream>
#include <array>
#include <string>
#include <cmath>

const int tailleMaxTableau = 12;

using TabPrecipitation = std::array<int, tailleMaxTableau>;

void Saisie (TabPrecipitation &tab)
{
    for (int k = 0; k < tailleMaxTableau; k++)
    {
        std::cout << "Saisir des valeurs entières pour chaque mois ("<< k + 1 <<"/12): ";
        std::cin >> tab[k];
    }
}

void Affichage (TabPrecipitation tab)
{
    for (int k = 0; k < tailleMaxTableau; k++)
    {
        std::cout << tab[k] + ", ";
    }
}

int Minimale (TabPrecipitation tab)
{
    int min = tab[0];

    for (int k = 1; k < tailleMaxTableau; k++)
    {
        if (tab[k] < min)
        {
            min = tab[k];
        }
    }

    return min;
}

int Min (int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else {
            return c;
        }
    }
    
    if (b < c)
    {
        return b;
    }
    
    return c;
}

int Max (int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else {
            return c;
        }
    }
    
    if (b > c)
    {
        return b;
    }
    
    return c;
}

int Maximale (TabPrecipitation tab)
{
    int max = tab[0];

    for (int k = 1; k < tailleMaxTableau; k++)
    {
        if (tab[k] > max)
        {
            max = tab[k];
        }
    }

    return max;
}

int main ()
{
    TabPrecipitation angers, nantes, rennes;

    std::cout << "Saisie des valeurs :" << std::endl;
    Saisie(angers);

    std::cout << "Saisie des valeurs :" << std::endl;
    Saisie(nantes);

    std::cout << "Saisie des valeurs :" << std::endl;
    Saisie(rennes);

    std::cout << std::endl << "Voici le minimum d'angers: " << Minimale(angers) << std::endl;
    std::cout << std::endl << "Voici le maximum de nantes: " << Maximale(nantes) << std::endl;

    std::cout << "Voici la valeur minimale de tout les tableaux: " << Min(Minimale(angers), Minimale(nantes), Minimale(rennes)) << std::endl;
    std::cout << "Voici la valeur maximale de tout les tableaux: " << Max(Maximale(angers), Maximale(nantes), Maximale(rennes)) << std::endl;

    return 0;
}