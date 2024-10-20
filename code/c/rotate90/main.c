#include "colors.c"

int main (void)
{
    int tailleMat1 = 10;
    int** mat1 = initialiserMatrice(tailleMat1);  

    // Afficher la matrice
    if (mat1 != NULL) {
        afficherMatrice(mat1, tailleMat1);

        mat1 = rotation90(mat1, tailleMat1);
        
        printf("\n\n");
        afficherMatrice(mat1, tailleMat1);

        // Libérer la mémoire de la matrice
        libererMatrice(mat1, tailleMat1);
    }

    return 0;
}
