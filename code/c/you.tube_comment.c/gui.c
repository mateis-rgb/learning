#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./env.c"
#include "./api.c"

// /**
//  * @brief Clear the terminal
//  * 
//  */
// void clearScreen (void);

// /**
//  * @brief Print the logo of the cli
//  * 
//  */
// void logo (void);

// /**
//  * @brief Print the help manual
//  * 
//  * @return int
//  */
// int help (void);

// /**
//  * @brief Ask to user for retrying
//  * 
//  * @return int 
//  */
// int retry (void);

// /**
//  * @brief Ask for method between QUIT(-1), HELP(0), GET_COMMENTS(1)
//  * 
//  * @return int 
//  */
// int askForMethod (void);

// /**
//  * @brief Ask the url for the request 
//  * 
//  * @return char* 
//  */
// char * askForUrl (void);

/**
 * @brief Display comment
 * 
 * @param comment 
 */
void print_comment (Comment comment);


// void clearScreen (void)
// {
// 	system("clear");
// }


// void logo (void)
// {
// 	printf("\x1b[1;31m                    _         _         \x1b[1;0m                                              _    \n");
// 	printf("\x1b[1;31m _   _  ___  _   _ | |_ _   _| |__   ___\x1b[1;0m     ___ ___  _ __ ___  _ __ ___   ___  _ __ | |_\x1b[1;35m   ___ \n");
// 	printf("\x1b[1;31m| | | |/ _ \\| | | || __| | | | '_ \\ / _ \\\x1b[1;0m   / __/ _ \\| '_ ` _ \\| '_ ` _ \\ / _ \\| '_ \\| __|\x1b[1;35m / __|\n");
// 	printf("\x1b[1;31m| |_| | (_) | |_| || |_| |_| | |_) |  __/\x1b[1;0m  | (_| (_) | | | | | | | | | | |  __/| | | | |_\x1b[1;35m | (__ \n");
// 	printf("\x1b[1;31m \\__, |\\___/ \\__,_(_)__|\\__,_|_.__/ \\___|\x1b[1;0m___\\___\\___/|_| |_| |_|_| |_| |_|\\___||_| |_|\\__\x1b[1;35m(_)___|\n");
// 	printf("\x1b[1;31m |___/                                 \x1b[1;0m|_____|                                 \n");
// }

// int help (void)
// {
// 	int temp = 0;

// 	printf("Ce programme vous permet de faire des requetes HTTP en GET ou POST.\n\n");
// 	printf("Ce programme developper en C utilise la bibliotheque libcurl pour les requetes.\n");

// 	printf("\n---------\n");
// 	printf("Credits : \n");
// 	printf("---------\n");
// 	printf("Name: %s\n", NAME);
// 	printf("Version: %s\n", VERSION);
// 	printf("Author: %s (%s)\n", AUTHOR, GITHUB);
// 	printf("GitHub Repository: %s\n\n", REPO);
// 	printf("Que voulez vous faire (quitter[0] / poursuivre le programme[1]) : ");
// 	scanf("%d", &temp);
	
// 	return temp;
// }

// int retry (void)
// {
// 	int temp = 0;

// 	printf("Voulez-vous recommencer (Non[0] Oui[1]) : ");
// 	scanf("%d", &temp);

// 	return temp;
// }

// int askForMethod(void)
// {
// 	int temp = 0;

// 	printf("\nCe programme vous permet d'afficher tout les commentaires d'une video youtube. Que voulez vous faire ?\n\n-1 => Quitter le programe.\n0  => Obtenir de l'aide.\n1  => Obtenir les commentaires d'une video youtube.\n2  => Effacer l'ecran\nMethode demandee : ");
// 	scanf("%d", &temp);

// 	return temp;
// }

// char * askForUrl (void)
// {
// 	// On initialise les variables
// 	char url_temp[256] = "";
// 	char * url = (char *) malloc(256 * sizeof (char));

// 	// On demande l'entrée à l'utilisateur
// 	printf("Entrez l'url que vous voulez tester : ");
// 	scanf("%s", &url_temp);

// 	// On copie la chaine de caractère dans la variable de renvoit
// 	strcpy(url, url_temp);

// 	// On retourne l'url
// 	return url;
// }

void fill_blank (int len)
{
	for (int k = 0; k < len; k++) printf(" ");
}

void display_line (int len)
{
	printf("+-");
	
	for (int k = 0; k < len; k++)
	{
		printf("-");
	}

	printf("+\n");
}

void print_comment (Comment comment)
{
	size_t author_len = strlen("Auteur : ") + strlen(comment.author);
	size_t content_len = strlen(comment.content);

	size_t max_len = 

	display_line((int)content_len);

	printf("| Auteur : %s", comment.author);
	fill_blank((int)(content_len - author_len));
	printf("|\n");

	display_line((int)content_len);

	printf("| %s |\n", comment.content);

	display_line((int)content_len);

	printf("| Uploaded_at : %")
}

int main (void) 
{
	Comment comment = getComment();

	print_comment(comment);

	return 0;
}
