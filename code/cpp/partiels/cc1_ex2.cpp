#include <iostream>
#include <array>

int main ()
{
    
    const int tailleTableauMax = 255;

    int tempNote, indiceActuel;
    float tempDuree, dureeTotal;
    bool estPresente = false;
    using tNotes = std::array<int, tailleTableauMax>;
    using tDurees = std::array<float, tailleTableauMax>;
    
    tNotes notes;
    tDurees durees;

    std::cout << "Saisi du morceau (pour arrêter saisissez une note ou une durée négative)." << std::endl;

    do
    {
        std::cout << "Entrez la fréquence d'une note de musique (un entier strictement positif): ";
        std::cin >> tempNote;
        if (tempNote>0){
            std::cout << "Entrez la durée de la note de musique (un nombre flotant strictement positif): ";
            std::cin >> tempDuree;

            if (tempNote > 0 or tempDuree > 0)
            {
                notes[indiceActuel] = tempNote;
                durees[indiceActuel] = tempDuree;

                indiceActuel++;
                dureeTotal += tempDuree;
            }
        }
    }
    while (tempNote > 0 or tempDuree > 0);

    // Affichage du morceau
    std::cout << "Le morceau: ";
    for (int k = 0; k < indiceActuel; k++)
    {
        std::cout << notes[k] << "(" << durees[k] << ") ";
    }
    std::cout << std::endl;

    std::cout << "Le morceau dure " << dureeTotal << " secondes." << std::endl;

    // Présence d'une note
    std::cout << "Quelle note vouslez-vous chercher: ";
    std::cin >> tempNote;

    for (int k = 0; k < indiceActuel; k++)
    {
        if (notes[k] == tempNote)
        {
            estPresente = true;
        }
    }

    if (estPresente == true)
    {
        std::cout << "La note est présente dans le morceau" << std::endl;
    }

    // Fusion des notes
    int k = 0;

    while(k < indiceActuel-1)
    {
        if (notes[k] == notes[k+1])
        {
            durees[k] += durees[k+1];

            for (int i = k+1; i < indiceActuel-1; i++)
            {
                notes[i] = notes[i+1];
                durees[i] = durees[i+1];
            }

            indiceActuel--;
        }
        else{
            k++;
        }
    }

    // Affichage du morceau
    std::cout << "Le morceau: ";
    for (int k = 0; k < indiceActuel; k++)
    {
        std::cout << notes[k] << "(" << durees[k] << ") ";
    }
    std::cout << std::endl;

    std::cout << "Le morceau dure " << dureeTotal << " secondes." << std::endl;

    return 0;
}