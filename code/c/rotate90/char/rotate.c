#include "./matrix.c"

/**
 * @brief Making 90° rotation of a matrix
 * 
 * @param matrice 
 * @param taille 
 * @return char** 
 */
char** rotation90 (char** matrice, int taille);

/**
 * @brief Switch two values from position [x, y]
 * 
 * @param matrice 
 * @param pos1 
 * @param pos2 
 * @return char** 
 */
char** echange (char** matrice, int tailleMatrice, int* pos1, int* pos2);


char** rotation90 (char** matrice, int taille)
{
    int i = 0;
    int j = 0;
    char** tempMatrice = copieMatrice(matrice, taille);

    for (i = 0; i < taille; i++)
    {
        for (j = i + 1; j < taille; j++)
        {
            tempMatrice = echange(tempMatrice, taille, (int[2]){i, j}, (int[2]){j, i});
        }

    }

    for (i = 0; i < taille; i++)
    {
        for (j = 0; j < taille / 2; j++)
        {
            tempMatrice = echange(tempMatrice, taille, (int[2]){i, j}, (int[2]){i, taille - j - 1});
        }

    }

    return tempMatrice;
}

char** echange (char** matrice, int tailleMatrice, int* pos1, int* pos2)
{
    char** tempMatrice = copieMatrice(matrice, tailleMatrice);
    int tempValue = tempMatrice[pos2[0]][pos2[1]];

    tempMatrice[pos2[0]][pos2[1]] = tempMatrice[pos1[0]][pos1[1]];
    tempMatrice[pos1[0]][pos1[1]] = tempValue;

    return tempMatrice;
}
