#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Clear the terminal
 * 
 */
void clearScreen (void);

/**
 * @brief Print the logo of the cli
 * 
 */
void logo (void);

/**
 * @brief Print the help manual
 * 
 * @return int
 */
int help (void);

/**
 * @brief Ask to user for retrying
 * 
 * @return int 
 */
int retry (void);

/**
 * @brief Ask for method between QUIT(-1), HELP(0), GET(1) and POST(2)
 * 
 * @return int 
 */
int askForMethod (void);

/**
 * @brief Ask the url for the request 
 * 
 * @return char* 
 */
char * askForUrl (void);

/**
 * @brief Ask for the body of POST
 * 
 * @return char* 
 */
char * askForPostBody (void);

void clearScreen (void)
{
	system("clear");
}

void logo (void)
{
	printf(" _     _   _                                           _\n");         
	printf("| |__ | |_| |_ _ __     _ __ ___  __ _ _   _  ___  ___| |_   ___ \n"); 
	printf("| '_ \\| __| __| '_ \\   | '__/ _ \\/ _` | | | |/ _ \\/ __| __| / __|\n");
	printf("| | | | |_| |_| |_) |  | | |  __/ (_| | |_| |  __/\\__ \\ |_ | (__ \n");
	printf("|_| |_|\\__|\\__| .__/___|_|  \\___|\\__, |\\__,_|\\___||___/\\__(_)___|\n");
	printf("              |_| |_____|           |_|                          \n");
}

int help (void)
{
	int temp = 0;

	printf("Ce programme vous permet de faire des requetes HTTP en GET ou POST.\n\n");
	printf("Ce programme developper en C utilise la bibliotheque libcurl pour les requetes.\n");

	printf("\n---------\n");
	printf("Credits : \n");
	printf("---------\n");
	printf("Name: http_request.c\n");
	printf("Version: 0.0.1(a)\n\n");
	printf("Author: mateis-rgb (https://github.com/mateis-rgb/)\n");
	printf("Que voulez vous faire (quitter[0] / poursuivre le programme[1]) : ");
	scanf("%d", &temp);
	
	return temp;
}

int retry (void)
{
	int temp = 0;

	printf("Voulez-vous recommencer (Non[0] Oui[1]) : ");
	scanf("%d", &temp);

	return temp;
}

int askForMethod(void)
{
	int temp = 0;

	printf("Choisissez une methode de requete HTTTP.\n-1 => Quitter le programe.\n0  => Obtenir de l'aide.\n1  => GET\n2  => POST\n3  => Effacer l'ecran\nMethode demandee : ");
	scanf("%d", &temp);

	return temp;
}

char * askForUrl (void)
{
	// On initialise les variables
	char url_temp[255] = "";
	char * url = (char *) malloc(255 * sizeof (char));

	// On demande l'entrée à l'utilisateur
	printf("Entrez l'url que vous voulez tester : ");
	scanf("%s", &url_temp);

	// On copie la chaine de caractère dans la variable de renvoit
	strcpy(url, url_temp);

	// On retourne l'url
	return url;
}

char * askForPostBody (void)
{
	// On initialise les variables
	char key_temp[256] = "";
	char value_temp[256] = "";
	char added_temp[512] = "";
	char * body = (char *) malloc(512 * sizeof (char));
	int k = 0;

	// On affiche les "règles"
	printf("Entrez le corps de la requete (entrez -1 en clef pour arreter).\n");

	do {
		// On demande une première entrée
		printf("Clef (%d): ", k);
		scanf("%s", &key_temp);

		// On regarde si l'utilisateur veut arrêter
		if (strcmp(key_temp, "-1") != 0)
		{
			// On fait la deuxième entrée
			printf("Valeur (%d): ", k);
			scanf("%s", &value_temp);

			// On fait les opérations pour afficher tels que:
			// key{1}=value{1}&...key{n}=value{n}&
			strcat(added_temp, key_temp);
			strcat(added_temp, "=");
			strcat(added_temp, value_temp);
			strcat(added_temp, "&");

			// On incrémente le compteur
			k++;
		}
	} 
	// Tant que l'utilisateur ne veut pas arrêter
	while (strcmp(key_temp, "-1") != 0);
	
	// On copie la variable temporaire dans la variable que l'on va retourner
	strcpy(body, added_temp);

	// On retourne le corps de la requête
	return body;
}
