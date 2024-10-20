#include "rotate.c"

void afficherCouleurs (char** matriceCouleurs, int taille);

int main (void)
{
    int taille = 10;
    char** colors = initialiserMatrice(taille);    
    int i = 0;

    colors[2][2] = 41;
    colors[3][4] = 42;
    colors[1][7] = 43;
    colors[4][1] = 44;

    for (i = 0; i < 4; i++)
    {
        afficherCouleurs(colors, taille);

        colors = rotation90(colors, taille);

        printf("\n");
    }

    return 0;
}

void afficherCouleurs (char** matriceCouleurs, int taille)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < taille; i++)
    {
        for (j = 0; j < taille; j++)
        {
            if (matriceCouleurs[i][j] >= 40 && matriceCouleurs[i][j] <= 47) printf("\e[%dm \e[0m", matriceCouleurs[i][j]);
            else printf("%d", matriceCouleurs[i][j]);
        }

        printf("\n");
    }
}
