#include <stdio.h>
#include <math.h>

int changeMode (void);

/**
 * @brief Permet de transformer une coordonnée cartesienne vers polaire
 * 
 * @param x 
 * @param y 
 * @param pR 
 * @param pTheta 
 */
void polaire (double x, double y, double *pR, double *pTheta);

/**
 * @brief Permet de transformer une coordonnée polaire vers cartesienne
 * 
 * @param r 
 * @param Theta 
 * @param pX 
 * @param pY 
 */
void cartesienne (double r, double Theta, double *pX, double *pY);


int main(void)
{
    double x = 0;
    double y = 0;
    double r = 0;
    double Theta = 0;

    int mode;

    do
    {
        mode = changeMode();

        if (mode == 0)
        {
            printf("\nQuel est la coordonnee de X: ");
            scanf("%lf", &x);

            printf("Quel est la coordonnee de Y: ");
            scanf("%lf", &y);

            polaire(x, y, &r, &Theta);

            printf("La valeur du rayon de R: %f\n", r);
            printf("L'angle Theta (rad): %f\n\n", Theta);
        }
        else if (mode == 1)
        {
            printf("\nQuel est la valeur du rayon de R: ");
            scanf("%lf", &r);

            printf("Quel est l'angle Theta: ");
            scanf("%lf", &Theta);

            cartesienne(r, Theta, &x, &y);

            printf("La coordonnee de X: %f\n", x);
            printf("La coordonnee de Y: %f\n\n", y);
        }
    }
    while (mode != -1);

    return 0;
}


int changeMode (void)
{
	int mode = -1;

    printf("  ____       _ ____   ____           _   \n");
    printf(" |  _ \\ ___ | |___ \\ / ___|__ _ _ __| |_ \n");
    printf(" | |_) / _ \\| | __) | |   / _` | '__| __|\n");
    printf(" |  __/ (_) | |/ __/| |__| (_| | |  | |_ \n");
    printf(" |_|   \\___/|_|_____|\\____\\__,_|_|   \\__|\n\n");
    printf("----------------------------------------- \n");
    printf("Convertisseur de coordonnees polaires vers cartesiennes et inversement.\n");
    printf("[0]  - Cartesienne => Polaire\n");
    printf("[1]  - Polaire => Cartesiennes\n");
    printf("[-1] - Quitter le programme\n");
    printf("Que choisissez vous de convertir ? ");

    scanf("%d", &mode);

    return mode;
}


void polaire (double x, double y, double *pR, double *pTheta)
{
    *pR = sqrt((x*x) + (y*y));
    *pTheta = atan2(y, x);
}


void cartesienne (double r, double Theta, double *pX, double *pY)
{
    *pX = r*cos(Theta);
    *pY = r*sin(Theta);
}
