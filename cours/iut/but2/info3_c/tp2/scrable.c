#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Prototypes des fonctions

/**
 * The function `AfficheChevalet` prints the contents of an array of characters.
 * 
 * @param pTableau The parameter `pTableau` is a pointer to a character array, which represents the
 * contents of a "chevalet" (a rack or holder). The function `AfficheChevalet` takes this character
 * array and an integer `Nb` as input. The integer `Nb` specifies
 * @param Nb The parameter `Nb` in the function `AfficheChevalet` represents the number of elements in
 * the array `pTableau` that you want to display. It is used as the limit for the loop that iterates
 * over the elements of the array to print them out.
 */
void AfficheChevalet(char *pTableau, int Nb);

/**
 * The function AjouteLettre randomly adds a letter (either uppercase or lowercase) to a given array if
 * the array is not already full.
 * 
 * @param pTableau The `pTableau` parameter is a pointer to a character array where letters will be
 * added by the `AjouteLettre` function.
 * @param pNb The parameter `pNb` is a pointer to an integer. It is used to keep track of the number of
 * elements currently stored in the array `pTableau`. The function `AjouteLettre` increments this value
 * after adding a new letter to the array.
 * 
 * @return The function `AjouteLettre` returns an integer value. If the condition `*pNb >= 7` is true,
 * it returns 0. Otherwise, it returns 1 after adding a randomly generated letter to the array pointed
 * to by `pTableau` and incrementing the value pointed to by `pNb`.
 */
int AjouteLettre(char *pTableau, int *pNb);

/**
 * The function VideChevalet sets the value pointed to by pNb to 0.
 * 
 * @param pNb The parameter `pNb` is a pointer to an integer.
 */
void VideChevalet(int *pNb);

/**
 * The function "Majuscule" converts lowercase letters in a character array to uppercase and returns a
 * flag indicating if any modifications were made.
 * 
 * @param pTableau The function `Majuscule` takes in a character array `pTableau` and an integer `Nb`
 * as parameters. The function iterates through the elements of the character array and converts any
 * lowercase letters to uppercase using the `toupper` function. If any modifications are made during
 * this process
 * @param Nb The parameter `Nb` in the `Majuscule` function represents the number of elements in the
 * array `pTableau`. It is used as the upper limit for the loop that iterates over the elements of the
 * array to check and convert lowercase letters to uppercase.
 * 
 * @return The function `Majuscule` returns an integer value indicating whether any lowercase letters
 * in the input array `pTableau` were modified to uppercase. If at least one lowercase letter was
 * modified, the function returns 1. Otherwise, it returns 0.
 */
int Majuscule(char *pTableau, int Nb);

/**
 * The function RegenereChevalet regenerates a scrabble rack by adding letters until it reaches a total
 * of 7 letters.
 * 
 * @param pTableau The parameter `pTableau` is a pointer to a character array, which likely represents
 * a game board or a set of letters in a game context.
 * @param pNb The parameter `pNb` is a pointer to an integer. It is used to keep track of the number of
 * elements in the array or the size of the array. In the function `RegenereChevalet`, it is being
 * passed by reference so that it can be modified within the function
 */
void RegenereChevalet(char *pTableau, int *pNb);

/**
 * The function `SupprimeLettre` removes a specified letter from a character array and updates the
 * array size accordingly.
 * 
 * @param pTableau The `pTableau` parameter is a pointer to a character array where the function
 * `SupprimeLettre` will search for the character `Lettre` and remove it from the array if found.
 * @param pNb The parameter `pNb` is a pointer to an integer that represents the number of elements in
 * the array `pTableau`. By dereferencing `pNb`, we can access and modify the value it points to, which
 * in this case is the number of elements in the array.
 * @param Lettre The parameter `Lettre` in the `SupprimeLettre` function represents the character that
 * you want to remove from the array `pTableau`. The function iterates through the array to find the
 * first occurrence of this character and then removes it by shifting all elements after it to the
 * 
 * @return The function `SupprimeLettre` returns an integer value. It returns 1 if the specified letter
 * `Lettre` is found and successfully removed from the array `pTableau`, otherwise it returns 0.
 */
int SupprimeLettre(char *pTableau, int *pNb, char Lettre);

/**
 * The TriChevalet function sorts an array of characters in uppercase alphabetically.
 * 
 * @param pTableau It looks like the code snippet you provided is a function named `TriChevalet` that
 * sorts the characters in an array in alphabetical order. The function takes a character array
 * `pTableau` and an integer `Nb` as parameters.
 * @param Nb The parameter `Nb` in the `TriChevalet` function represents the number of elements in the
 * array `pTableau`. It is used to determine the length of the array and to iterate over its elements.
 */
void TriChevalet(char *pTableau, int Nb);

// Fonction principale
int main (void) 
{
    char Chevalet[7];
    int NbLettre = 0;
    char choix;

    srand(time(0));

    do 
	{
        printf("\n--- Menu ---\n");
        printf("p. Afficher le chevalet\n");
        printf("a. Ajouter une lettre\n");
        printf("e. Vider le chevalet\n");
        printf("c. Convertir en majuscules\n");
        printf("r. Régénérer le chevalet\n");
        printf("d. Supprimer une lettre\n");
        printf("s. Trier le chevalet\n");
        printf("q. Quitter\n");
        printf("Choix : ");

		choix = getchar();

		// Nettoyer le buffer d'entrée (pour éviter les problèmes avec les retours à la ligne)
        while (getchar() != '\n');

        if (choix == 'p') 
		{
			AfficheChevalet(Chevalet, NbLettre);
		} else if (choix == 'a') 
		{
			if (AjouteLettre(Chevalet, &NbLettre)) 
			{
				printf("Lettre ajoutée.\n");
			} else 
			{
				printf("Chevalet plein.\n");
			}
		} else if (choix == 'e') 
		{
			VideChevalet(&NbLettre);
			
			printf("Chevalet vidé.\n");
		} else if (choix == 'c') 
		{
			if (Majuscule(Chevalet, NbLettre)) 
			{
				printf("Minuscules converties en majuscules.\n");
			} else 
			{
				printf("Toutes les lettres sont déjà en majuscules.\n");
			}
		} else if (choix == 'r') 
		{
			RegenereChevalet(Chevalet, &NbLettre);
		
			printf("Chevalet régénéré.\n");
		} else if (choix == 'd') 
		{
			char lettre;
			
			printf("Lettre à supprimer : ");
			scanf(" %c", &lettre);

			if (SupprimeLettre(Chevalet, &NbLettre, lettre)) 
			{
				printf("Lettre supprimée.\n");
			} else 
			{
				printf("Lettre non trouvée.\n");
			}
		} else if (choix == 's') 
		{
			TriChevalet(Chevalet, NbLettre);

			printf("Chevalet trié.\n");
		} else if (choix == 'q') 
		{
			printf("Au revoir !\n");
		} else 
		{
			printf("Choix invalide.\n");
		}

    } 
	while (choix != 'q');

    return 0;
}

// Exercice 2
void AfficheChevalet(char *pTableau, int Nb) 
{
    printf("Contenu du chevalet : ");

    for (int i = 0; i < Nb; i++) 
	{
        printf("%c ", pTableau[i]);
    }

    printf("\n");
}

// Exercice 3
int AjouteLettre(char *pTableau, int *pNb) 
{
    if (*pNb >= 7) return 0;

    char lettre;
    int estMaj = rand() % 2;

    lettre = estMaj ? 'A' + (rand() % 26) : 'a' + (rand() % 26);

    pTableau[*pNb] = lettre;
    (*pNb)++;
    
	return 1;
}

// Exercice 4
void VideChevalet(int *pNb) 
{
    *pNb = 0;
}

// Exercice 5
int Majuscule(char *pTableau, int Nb) 
{
    int modifie = 0;

    for (int i = 0; i < Nb; i++) 
	{
        if (islower(pTableau[i])) 
		{
            pTableau[i] = toupper(pTableau[i]);
            modifie = 1;
        }
    }

    return modifie;
}

// Exercice 6
void RegenereChevalet(char *pTableau, int *pNb) 
{
    VideChevalet(pNb);

    while (*pNb < 7) 
	{
        AjouteLettre(pTableau, pNb);
    }
}

// Exercice 7
int SupprimeLettre(char *pTableau, int *pNb, char Lettre) 
{
    for (int i = 0; i < *pNb; i++) 
	{
        if (pTableau[i] == Lettre) 
		{
            for (int j = i; j < *pNb - 1; j++) 
			{
                pTableau[j] = pTableau[j + 1];
            }
    
			(*pNb)--;
    
			return 1;
        }
    }

    return 0;
}

// Exercice 8
void TriChevalet(char *pTableau, int Nb) 
{
    char temp[7] = {0};
    int indexTemp = 0;

    // Convertir en majuscules
    for (int i = 0; i < Nb; i++) 
	{
        pTableau[i] = toupper(pTableau[i]);
    }

    // Parcourir l'alphabet
    for (char c = 'A'; c <= 'Z'; c++) 
	{
        for (int i = 0; i < Nb; i++) 
		{
            if (pTableau[i] == c) 
			{
                temp[indexTemp++] = pTableau[i];
                
				// Décaler les lettres restantes
                for (int j = i; j < Nb - 1; j++) 
				{
                    pTableau[j] = pTableau[j + 1];
                }

                Nb--;
                i--; // Re-vérifier la même position
            }
        }
    }

    // Recopier le tableau trié
    for (int i = 0; i < indexTemp; i++)
	{
        pTableau[i] = temp[i];
    }

    *(&Nb) = indexTemp; // Mise à jour du nombre de lettres (optionnel selon contexte)
}
