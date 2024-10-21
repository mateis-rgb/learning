#include "rotate.c"

/**
 * @brief Prints good colors, from a matrix
 * 
 * @param matriceCouleurs 
 * @param taille 
 */
void afficherCouleurs (char** matriceCouleurs, int taille);


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
