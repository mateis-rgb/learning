#include "colors.c"

int main (void)
{
    int taille = 10;
    char** colors = initialiserMatrice(taille);    
    int i = 0;
    int cpt = 41;

    for (i = 0; i < taille; i++)
    {
        if (cpt >= 40 && cpt < 47) cpt++;
        else cpt = 41;

        colors[i][i] = cpt;
    }

    afficherCouleurs(colors, taille);

    colors = rotation90(colors, taille);

    printf("\n");

    afficherCouleurs(colors, taille);

    return 0;
}