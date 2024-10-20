#include "../include.h"

/**
 * @brief Initialize matrix with 1 to n values inside of it
 * 
 * @param n 
 * @return char** 
 */
char** initialiserMatrice (int n);

/**
 * @brief Free memory of each lines of matrix
 * 
 * @param matrice 
 * @param n 
 */
void libererMatrice (char** matrice, int n);

/**
 * @brief Display matrix
 * 
 * @param matrice 
 * @param taille 
 */
void afficherMatrice (char** matrice, int taille);

/**
 * @brief Allow to copy matrice into an other instance
 * 
 * @param matrice 
 * @param taille 
 * @return char** 
 */
char** copieMatrice (char** matrice, int taille);

char** initialiserMatrice (int n)
{
    char** matrice = (char**)malloc(n * sizeof(char*)); // Allouer de la mémoire pour un tableau de pointeurs

    // Gestion des erreurs sur l'allocation de la mémoire
    if (matrice == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        return NULL;
    }

    // Allouer de la mémoire pour chaque ligne de la matrice
    for (int i = 0; i < n; i++) {
        matrice[i] = (char*)malloc(n * sizeof(char));
        
        if (matrice[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        
            // Libérer la mémoire déjà allouée en cas d'erreur
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }

            free(matrice);
            
            return NULL;
        }
        
        // Initialiser chaque élément à 0
        for (int j = 0; j < n; j++) {
            matrice[i][j] = 46;
        }
    }

    return matrice;
}


void libererMatrice (char** matrice, int n)
{
    for (int i = 0; i < n; i++) {
        free(matrice[i]); // Libérer chaque sous tableau de la matrice
    }

    // Libérer la matrice
    free(matrice);
}


void afficherMatrice (char** matrice, int taille)
{
    int i = 0;
    int j = 0;

    // Parcours de la matrice
    for (i = 0; i < taille; i++)
    {
        for (j = 0; j < taille; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        
        printf("\n");
    }
}

char** copieMatrice (char** matrice, int taille)
{
    // Création d'une matrice neuve, peuplé de 0
    char** tempMatrice = initialiserMatrice(taille);

    int i = 0;
    int j = 0;

    for (i = 0; i < taille; i++)
    {
        for (j = 0; j < taille; j++)
        {
            // On copie chaque valeurs de la matrice précedante dans une nouvelle matrice
            tempMatrice[i][j] = matrice[i][j];
        }
    }

    return tempMatrice;
}
